#ifndef _NAIVE_CLASSIFIER_H_
#define _NAIVE_CLASSIFIER_H_

#include <string>
#include <vector>
#include <unordered_map>

class NaiveClassifier
{
public:
    void train(std::string trainDataFilePath, std::string probsFilePath);
    bool isGoodComment(std::string comment);
    void test(std::string testDataFilePath);

private:
    double goodProb;
    double badProb;
    std::unordered_map<std::string, double> wordsGoodProb;
    std::unordered_map<std::string, double> wordsBadProb;

    void addConditionalProbs(std::string trainDataFilePath);
    void addSingleProbs(std::string probsFilePath);

    void printTestResults(const std::vector<bool> &labels, const std::vector<bool> &predicts);
    double getAccuracy(const std::vector<bool> &labels, const std::vector<bool> &predicts);
    double getPrecision(const std::vector<bool> &labels, const std::vector<bool> &predicts);
    double getRecall(const std::vector<bool> &labels, const std::vector<bool> &predicts);
};

#endif