#define _CRT_SECURE_NO_WARNINGS

#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/face/facerec.hpp"

#include <memory>
#include <iostream>
#include <string>
#include <filesystem>
#include <stdio.h>
#include <conio.h>

namespace fs = std::filesystem;
using namespace cv;
using namespace std;

//Класс обеспечивающий распознование лиц и поиск совпадений в базе данных.
class FaceRecognition
{
private:
	CascadeClassifier faceCascade;
	shared_ptr<cv::face::LBPHFaceRecognizer> recognizer;

public:
	
	FaceRecognition(const fs::path& haarcascade_frontalface_default_Path, const fs::path& data_recognizer_Path) {
		faceCascade.load("Resources/haarcascade_frontalface_default.xml");
		if (faceCascade.empty()) {
			cout << "XML file not loaded" << endl;
		}
		recognizer = cv::face::LBPHFaceRecognizer::create(1, 8, 8, 8, 123);
		recognizer.get()->read(data_recognizer_Path.string());
	}

	bool TrainingRecognize(const string& data_recognizer_Path, const string& training_data_Path, int minID = 0, int maxID = 99){
		vector<Mat> ready_made_faces;
		vector<int> labels;
		
		for (int i = minID; i <= maxID; ++i) {
			string workdir = training_data_Path + "/" + "test" + to_string(i) + ".jpg";
			Mat srcImage;
			srcImage = imread(workdir, IMREAD_GRAYSCALE);

			vector<Rect>faces;
			faceCascade.detectMultiScale(srcImage, faces, 1.1, 5, 0, Size(30, 30));
			
			if (!faces.empty()) {
				ready_made_faces.push_back(srcImage(faces.at(0)));
				labels.push_back(i);
			}
			else {
				cout << "\tWarning gninraW\n";
				return 1;
			}
		}

		recognizer.get()->train(ready_made_faces, labels);
		{
			FILE* fp;
			fp = fopen(data_recognizer_Path.c_str(), "w");
			fclose(fp);
		}
		recognizer.get()->write(data_recognizer_Path);
		return 0;
	}

	int FindPerson(Mat& src, double& the_algorithm_is_sure) {
		
		vector<Rect>faces;
		faceCascade.detectMultiScale(src, faces, 1.1, 5, 0, Size(30, 30));
		Mat Face = src(faces[0]);

		int predicted_label = -1;
		double predicted_confidence = 0.0;
		recognizer.get()->predict(Face, predicted_label, the_algorithm_is_sure);

		return predicted_label;
	}

};


int main() {
	string the_path_to_the_custom_recognizer = "recognizer.xml";
	string haarcascade_frontalface_default = "Resources/haarcascade_frontalface_default.xml";
	
	FaceRecognition Face(haarcascade_frontalface_default, the_path_to_the_custom_recognizer);
	Face.TrainingRecognize(the_path_to_the_custom_recognizer, "Resources", 1, 8);
	Mat src = imread("Resources/monkey/test.jpg", IMREAD_GRAYSCALE);
	
	double the_algorithm_is_sure = 0.0;
	int a = Face.FindPerson(src, the_algorithm_is_sure);
	
	string path = "Resources/test" + to_string(a) + ".jpg";
	Mat sffds = imread(path);
	imshow("asdf", sffds);
	waitKey(0);
	return 0;
}