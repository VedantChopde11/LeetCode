class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> days = {31,28,31,30,31,30,31,31,30,31,30,31};

        int alicearr = 0;
        int bobarr = 0;
        int alicele = 0;
        int boble = 0;

        for(int i = 0 ; i < 2; i++){
            if(arriveAlice[0] == '0'){
                alicearr = arriveAlice[1] - '0'; 
            }
            else{
                alicearr = stoi(arriveAlice.substr(0,2));
            }

            if(leaveAlice[0] == '0'){
                alicele = leaveAlice[1] - '0'; 
            }
            else{
                alicele = stoi(leaveAlice.substr(0,2));
            }

            if(arriveBob[0] == '0'){
                bobarr = arriveBob[1] - '0'; 
            }
            else{
                bobarr = stoi(arriveBob.substr(0,2));
            }

            if(leaveBob[0] == '0'){
                boble = leaveBob[1] - '0'; 
            }
            else{
                boble = stoi(leaveBob.substr(0,2));
            }
        }

        int dalicearr = 0;
        int dbobarr = 0;
        int dalicele = 0;
        int dboble = 0;

        for(int i = 3 ; i < 5; i++){
            if(arriveAlice[3] == '0'){
                dalicearr = arriveAlice[4] - '0'; 
            }
            else{
                dalicearr = stoi(arriveAlice.substr(3,2));
            }

            if(leaveAlice[3] == '0'){
                dalicele = leaveAlice[4] - '0'; 
            }
            else{
                dalicele = stoi(leaveAlice.substr(3,2));
            }

            if(arriveBob[3] == '0'){
                dbobarr = arriveBob[4] - '0'; 
            }
            else{
                dbobarr = stoi(arriveBob.substr(3,2));
            }

            if(leaveBob[3] == '0'){
                dboble = leaveBob[4] - '0'; 
            }
            else{
                dboble = stoi(leaveBob.substr(3,2));
            }
        }

        int arrm = 0;
        int arrd = 0;
        int levm = 0;
        int levd = 0;

        if(bobarr == alicearr){
            if(dbobarr > dalicearr){
                arrm = bobarr;
                arrd = dbobarr;
            }
            else{
                arrm = alicearr;
                arrd = dalicearr;
            }
        }
        else if(bobarr > alicearr){
            arrm = bobarr;
            arrd = dbobarr;
        }
        else{
            arrm = alicearr;
            arrd = dalicearr;
        }

        if(boble == alicele){
            if(dboble < dalicele){
                levm = boble;
                levd = dboble;
            }
            else{
                levm = alicele;
                levd = dalicele;
            }
        }
        else if(boble < alicele){
            levm = boble;
            levd = dboble;
        }
        else{
            levm = alicele;
            levd = dalicele;
        }

        if(levm < arrm) return 0;
        if(levm == arrm && levd < arrd) return 0;

        int ans = 0;

        if(levm == arrm){
            ans += levd - arrd + 1;
        } 
        else{
            ans += days[arrm - 1] - arrd + 1;

            for(int i = arrm; i < levm - 1; i++){
                ans += days[i];
            }

            ans += levd;
        }
        return ans;
    }
};