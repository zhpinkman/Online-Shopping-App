#include <cmath>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "NaiveClassifier.hpp"
#include "Tools.hpp"
#include "constants.hpp"
using namespace std;

void NaiveClassifier::train(string trainDataFilePath, string probsFilePath)
{
    addConditionalProbs(trainDataFilePath);
    addSingleProbs(probsFilePath);
}

void NaiveClassifier::addConditionalProbs(string trainDataFilePath)
{
    ifstream file = Tools::openCSVFile(trainDataFilePath);
    vector<vector<string>> trainData = Tools::parseCSVFile(file);
    file.close();

    for(int i = 1; i < trainData.size(); i++)
    {
        string word = trainData[i][0];

        double wordGoodProb = stod(trainData[i][1]);
        wordsGoodProb[word] = wordGoodProb;

        double wordBadProb = stod(trainData[i][2]);
        wordsBadProb[word] = wordBadProb;
    }
}

void NaiveClassifier::addSingleProbs(string probsFilePath)
{
    ifstream file = Tools::openCSVFile(probsFilePath);
    vector<vector<string>> probsData = Tools::parseCSVFile(file);
    file.close();

    goodProb = stod(probsData[1][0]);
    badProb = stod(probsData[1][1]);
}

bool NaiveClassifier::isGoodComment(std::string comment)
{
    double goodComemntProb = log(goodProb);
    double badCommentProb = log(badProb);
    vector<string> commentWords = Tools::splitByChar(comment, SPACE);

    for(string commentWord : commentWords)
    {
        double wordGoodProb = wordsGoodProb[commentWord];
        double wordBadProb = wordsBadProb[commentWord];

        if(wordGoodProb != 0 && wordBadProb != 0)
        {
            goodComemntProb += log(wordGoodProb);
            badCommentProb += log(wordBadProb);
        }
        else if(wordGoodProb == 0 && wordBadProb != 0)
            return false;
        else
            return true;
    }

    return (goodComemntProb >= badCommentProb);
}

void NaiveClassifier::test(string testDataFilePath)
{
    ifstream file = Tools::openCSVFile(testDataFilePath);
    vector<vector<string>> testData = Tools::parseCSVFile(file);
    file.close();

    vector<bool> testLabels;
    for(int i = 1; i < testData.size(); i++)
        testLabels.push_back(Tools::stringToBool(testData[i][1]));

    vector<bool> testPredicts;
    for(int i = 1; i < testData.size(); i++)
        testPredicts.push_back(isGoodComment(testData[i][1]));

    printTestResults(testLabels, testPredicts);
}

void NaiveClassifier::printTestResults(const vector<bool> &labels, const vector<bool> &predicts)
{
    cout << "Recall: " << getRecall(labels, predicts) << '\n';
    cout << "Precission: " << getPrecision(labels, predicts) << '\n';
    cout << "Accuracy: " << getAccuracy(labels, predicts) << '\n';
}

double NaiveClassifier::getAccuracy(const vector<bool> &labels, const vector<bool> &predicts)
{
    int correctDetectedCount = 0;
    for(int i = 0; i < labels.size(); i++)
        correctDetectedCount += (int)(labels[i] == predicts[i]);

    return ((double)correctDetectedCount / (double)labels.size());   
}

double NaiveClassifier::getPrecision(const vector<bool> &labels, const vector<bool> &predicts)
{
    int correctGoodsCount = 0;
    for(int i = 0; i < labels.size(); i++)
        correctGoodsCount += (int)(labels[i] == true && predicts[i] == true);
    
    int goodDetectedsCount = count(predicts.begin(), predicts.end(), true);

    return ((double)correctGoodsCount / (double)goodDetectedsCount); 
}

double NaiveClassifier::getRecall(const vector<bool> &labels, const vector<bool> &predicts)
{
    int correctGoodsCount = 0;
    for(int i = 0; i < labels.size(); i++)
        correctGoodsCount += (int)(labels[i] == true && predicts[i] == true);
    
    int goodsCount = count(labels.begin(), labels.end(), true);

    return ((double)correctGoodsCount / (double)goodsCount);
}