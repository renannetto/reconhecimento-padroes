#ifndef ANOVA_H
#define ANOVA_H

#include <vector>

using namespace std;

struct anova
{
    vector<float> sqentre;
    vector<float> sqdentro;
    vector<float> fscore;
    vector<bool> resultado;
};

#endif // ANOVA_H
