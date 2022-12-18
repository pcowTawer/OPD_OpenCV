#include "facerecognition.h"
#include "database.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/face/facerec.hpp"

#include <string>
#include <iostream>
#include <ctime>

//#include <stdio.h>
//#include <conio.h>
const string current_path = "C:/Users/PCOW/Documents/qtproj/OPD3/";

FaceRecognition::FaceRecognition(const string& haarcascade_frontalface_default_Path, const string& data_recognizer_Path, const string& data_base_name, bool flag):
    DB(DBase(data_base_name))
{
    faceCascade.load(haarcascade_frontalface_default_Path);
    if (faceCascade.empty()) {
        cout << "XML file not loaded" << endl;
    }
    recognizer = cv::face::LBPHFaceRecognizer::create(1, 8, 8, 8, 123);
    if(flag){
        TrainingRecognize(data_recognizer_Path);
    }
    else {
        recognizer->read(data_recognizer_Path);
    }
}

bool FaceRecognition::TrainingRecognize(const string& data_recognizer_Path, int minID, int maxID)
{
    vector<Mat> ready_made_faces;
    vector<int> labels;
    DB.clearbus();
    DB.execute(DB, string("SELECT MAX (ID) FROM PEOPLE"));
    string MAXID = DBase::get_the_first_response_received().second;
    DB.clearbus();

    DB.execute(DB, string("SELECT MIN (ID) FROM PEOPLE"));
    string MINID = DBase::get_the_first_response_received().second;


    for (int i = std::stoi(MINID); i < std::stoi(MAXID); ++i) {

        DB.clearbus();
        DB.execute(DB, string("SELECT IMG FROM PEOPLE WHERE ID = ") + to_string(i));

        for (;!DBase::empty();) {

            /////// Тут должно быть обращение к базе данных===========================================================================================

            string workdir = current_path + DBase::get_the_first_response_received().second;

            /////// Тут должно быть обращение к базе данных===========================================================================================

            if(workdir == std::string("NULL")){cout<<"This is BASE"<<endl; continue;}

            Mat faces;
            faces = imread(workdir, IMREAD_GRAYSCALE);

            if (!faces.empty()) {
                ready_made_faces.push_back(faces);
                labels.push_back(i);
            }
            else {
                cout << "\tWarning gninraW\n";
                return 0;
            }
        }
    }
    recognizer->train(ready_made_faces, labels);
    {
       FILE* fp;
       fp = fopen(data_recognizer_Path.c_str(), "w");
       fclose(fp);
    }
    recognizer.get()->write(data_recognizer_Path);
    return 1;
}

int FaceRecognition::FindPerson(Mat& src, int& predicted_label, double& the_algorithm_is_sure) {

    vector<Rect>faces;
    faceCascade.detectMultiScale(src, faces, 1.1, 11, 0, Size(30, 30));

    if (faces.empty()) return false;

    Mat Face = src(faces[0]);

    for(int i = 0; i < faces.size(); ++i){
        rectangle(src, faces[i].br(),faces[i].tl(), 255 , 5);
    }
    predicted_label = -1;
    the_algorithm_is_sure = 0.0;

    recognizer->predict(Face, predicted_label, the_algorithm_is_sure);

    return true;
}

int FaceRecognition::FindPerson(Mat& src, vector<int>& predicted_label, vector<double>& the_algorithm_is_sure) {

    vector<Rect>faces;
    faceCascade.detectMultiScale(src, faces, 1.1, 5, 0, Size(30, 30));

    if (faces.empty()) return false;

    for (int i = 0; i < faces.size(); ++i) {
        Mat Face = src(faces.at(i));
        recognizer.get()->predict(Face, predicted_label.at(i), the_algorithm_is_sure.at(i));
    }
    for(int i = 0; i < faces.size(); ++i) {
        cv::rectangle(src, faces.at(i), Scalar(1,0,0,0), 5);
    }
    return true;
}

int FaceRecognition::add_unidentified_persons_to_the_database(const Mat &src){
    vector<Rect>faces;
    faceCascade.detectMultiScale(src, faces, 1.1, 11, 0, Size(30, 30));

    for (int i = 0; i < faces.size(); ++i) {
        Mat face = src(faces[i]);
        time_t now = time(0);
        string someName = to_string(now/(i+1)) + ".jpg";
        imwrite((current_path + "PEOPLE/" +someName), face); // A JPG FILE IS BEING SAVED
        DBase::execute(DB, "INSERT INTO PEOPLE (`IMG`) VALUES ('PEOPLE/" +someName + "')");
    }

    return 1;
}

int FaceRecognition::add_unidentified_persons_to_the_database(const Mat &src, int ID){
    vector<Rect>faces;
    faceCascade.detectMultiScale(src, faces, 1.1, 11, 0, Size(30, 30));

    for (int i = 0; i < faces.size(); ++i) {
        Mat face = src(faces[i]);
        time_t now = time(0);
        string someName = to_string(now/(i+1)) + ".jpg";
        imwrite((current_path + "PEOPLE/" +someName), face); // A JPG FILE IS BEING SAVED
        DBase::execute(DB, "INSERT INTO PEOPLE (`ID`,`IMG`) VALUES (" + to_string(ID) + ",'PEOPLE/" +someName + "')");
    }

    return 1;
}
