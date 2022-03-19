#include<bits/stdc++.h>
using namespace std;


#define sz 105
bool isFreeCandidate[sz];
int n,companyRecruited[sz];
vector<int>candidatesPref[sz], companysPref[sz];

void Clean(int n)
{
    for(int i=0 ; i<=n ; i++) {
        candidatesPref[i].clear();
        companysPref[i].clear();
        companyRecruited[i] = -1;
        isFreeCandidate[i] = true;
    }
}

bool ComPreferCand2OverCand1(int com, int cand1, int cand2)
{
    for(int candidate : companysPref[com]){
        if(candidate == cand2)
            return true;

        if(candidate == cand1)
            return false;
    }
}

void StableMarriage()
{
    int freeCandidates = n;

    while(freeCandidates)
    {
        int candidate = -1;
        for(candidate=1 ; candidate <= n ; candidate++) {
            if(isFreeCandidate[candidate])
                break;
        }

        for(int i=0 ; i < candidatesPref[candidate].size() && isFreeCandidate[candidate] ; i++) {
            int x = candidatesPref[candidate][i];
            int company = x-n;
            if(companyRecruited[company] == -1) {
                companyRecruited[company] = candidate;
                isFreeCandidate[candidate] = false;
                freeCandidates--;
            }
            else {
                if(ComPreferCand2OverCand1(company, companyRecruited[company], candidate)) {
                    isFreeCandidate[companyRecruited[company]] = true;
                    companyRecruited[company] = candidate;
                    isFreeCandidate[candidate] = false;
                }
            }
        }
    }
}

void Solve(int t)
{
    scanf("%d", &n);
    for(int candidate=1 ; candidate <= n ; candidate++) {
        for(int j=1 ; j<=n ; j++) {
            int company;
            scanf("%d", &company);

            candidatesPref[candidate].push_back(company);
        }
    }

    for(int company=1 ; company <= n ; company++) {
        for(int j=1 ; j<=n ; j++) {
            int candidate;
            scanf("%d", &candidate);

            companysPref[company].push_back(candidate);
        }
    }

    StableMarriage();

    

    printf("Case %d:",t);
    for(int i=1 ; i<=n ; i++) {
        printf(" (%d %d)", companyRecruited[i], i+n);
    }
    printf("\n");
    Clean(n);
}

int main()
{
    for(int i=0 ; i<sz ; i++) {
        companyRecruited[i] = -1;
        isFreeCandidate[i] = true;
    }

    int T;
    scanf("%d", &T);

    for(int t=1 ; t<=T ; t++){
        Solve(t);
    }

    return 0;
}
