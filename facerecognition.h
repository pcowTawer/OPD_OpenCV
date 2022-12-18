#ifndef FACERECOGNITION_H
#define FACERECOGNITION_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/face/facerec.hpp"
#include <string>

#include <memory>
#include <iostream>
#include <stdio.h>
#include <conio.h>

#include "database.h"

using namespace cv;
using namespace std;

//Класс обеспечивающий распознование лиц и поиск совпадений в базе данных.
class FaceRecognition
{
private:
    DBase DB;
    CascadeClassifier faceCascade;
    Ptr<cv::face::LBPHFaceRecognizer> recognizer;

public:

    FaceRecognition(const string& haarcascade_frontalface_default_Path, const string& data_recognizer_Path, const string& data_base_name, bool flag = false);

    bool TrainingRecognize(const string& data_recognizer_Path, int minID = 0, int maxID = 99);

    int FindPerson(Mat& src, int& predicted_label, double& the_algorithm_is_sure);

    int FindPerson(Mat& src, vector<int>& predicted_label, vector<double>& the_algorithm_is_sure);

    int add_unidentified_persons_to_the_database(const Mat &src);

    int add_unidentified_persons_to_the_database(const Mat &src, int ID);
};

#endif // FACERECOGNITION_H
