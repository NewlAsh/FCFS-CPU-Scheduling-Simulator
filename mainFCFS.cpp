#include <bits/stdc++.h>
using namespace std;

class inputProcess{

    private:
        string process;
        int arrivalTime;
        int burstTime;
        int completionTime;
        int waitingTime;
        int turnAroundTime;
       
    public:
        inputProcess(const string& p, const int& aT,  int& bT, int& cT,  int& wT,  int& taT){
            process = p;
            arrivalTime = (aT);
            burstTime = (bT);
            completionTime = (cT);
            waitingTime = (wT);
            turnAroundTime = (taT);
        }
        
        string getProcess() const {
            return process;
        }

        int getArrivalTime() const {
            return arrivalTime;
        }

        int getBurstTime() const {
            return burstTime;
        }

        int getCompletionTime() const {
            return completionTime;
        }

        int getTurnAroundTime() const {
            return turnAroundTime;
        }

        int getWaitingTime() const {
            return waitingTime;
        }

        
        
    };

    class scheduler{
        private:
            int arrival;
            int burst;
            int completion = 0;
            int waiting;
            int turnAround;
            string foundProcess;
            int sumWT=0, sumTAT=0;
            
        public:
            vector<inputProcess>processes;
            string line;
            int cnt=0;
        
            // vector<string>processname;
            // vector<string>arrivaltime;
            // vector<string>bursttime;
        
            void readFile(const string& fileName){
                ifstream fin(fileName);
                while(getline(fin, line)){
                    stringstream ss(line);

                    ss >> foundProcess;
                    ss >> arrival;
                    ss >> burst;


                    int startTime = max(completion, arrival);
                    completion = startTime + burst;
                    turnAround = completion - arrival;
                    waiting = turnAround - burst;

                    sumWT += waiting;
                    sumTAT += turnAround;

                    // processname.push_back(foundProcess);
                    // arrivaltime.push_back(foundAt);
                    // bursttime.push_back(foundBt);

                    processes.push_back(inputProcess(foundProcess, arrival, burst, completion, turnAround, waiting));
                    cnt++;

                }
            }
            
            void printCalc(const string& fileName){
                ofstream fout("scheduled.txt");
                fout<<"Complete Schedule and Time is mentioned"<<endl<<endl;
                fout<<"Here FCFS concept is used"<<endl<<endl;
                fout<<"The query had "<<cnt<<" processes to handle:- "<<endl<<endl<<endl;
                fout<<"Processes"<<"      "<<"Arrival Time"<<"     "<<"Burst Time"<<"      "<<"Comepletion Time"<<"     "<<"TurnAround Time"<<"      "<<"Waiting Time"<<endl<<endl;
                
                
                
                for(const auto& s : processes){
                    fout<<s.getProcess()<<"                  ";
                    fout<<s.getArrivalTime()<<"               ";
                    fout<<s.getBurstTime()<<"               ";
                    fout<<s.getCompletionTime()<<"                     ";
                    fout<<s.getTurnAroundTime()<<"                     ";
                    fout<<s.getWaitingTime()<<"                   ";

                    fout<<endl<<endl;
                }
                
                fout<<endl<<endl;
                fout<<"Avg waiting time :    "<<(float(sumWT)/cnt)<<" Seconds"<<endl<<endl;
                fout<<"Avg turnAround time : "<<(float(sumTAT)/cnt)<<" Seconds"<<endl<<endl; 
            }
    };
     

int main(){

    scheduler sch;
    sch.readFile("processes.txt");
    sch.printCalc("processes.txt");


    return 0;
}