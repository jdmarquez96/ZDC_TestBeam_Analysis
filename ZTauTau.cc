#include "TreeReader.h"
#include "WeightCalculator.h"
#include <string>
#include <ostream>

int main(int argc, char** argv) {
    using namespace std;
    
    
    std::string out = *(argv + 1);
    
    cout << "\n\n\n OUTPUT NAME IS:    " << out << endl;     //PRINTING THE OUTPUT File name
    TFile *fout = TFile::Open(out.c_str(), "RECREATE");
    
    std::string input = *(argv + 2);
    cout << "\n\n\n InPUT NAME IS:    " << input << endl;     //PRINTING THE Input File name
    TFile * myFile = TFile::Open(input.c_str());

    
    
    
    TH1F *    ChargeSum = new TH1F ("ChargeSum","ChargeSum", 300, 0, 300);

    
    
    
    TTree *Run_Tree = (TTree*) myFile->Get("tree");
    
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(6);
    
    Run_Tree->SetBranchAddress("ADC_11_0", &ADC_11_0);  // EM Channel 1  
    Run_Tree->SetBranchAddress("ADC_11_1", &ADC_11_1);  // EM Channel 2 
    Run_Tree->SetBranchAddress("ADC_11_2", &ADC_11_2);  // EM Channel 3  
    Run_Tree->SetBranchAddress("ADC_11_3", &ADC_11_3);  // EM Channel 4  
    Run_Tree->SetBranchAddress("ADC_11_4", &ADC_11_4);  // EM Channel 5     
    Run_Tree->SetBranchAddress("ADC_11_5", &ADC_11_5);  // EM Channel 6  
    Run_Tree->SetBranchAddress("ADC_11_6", &ADC_11_6);  // EM Channel 7  
    Run_Tree->SetBranchAddress("ADC_11_7", &ADC_11_7);  // EM Channel 8  
    Run_Tree->SetBranchAddress("ADC_11_8", &ADC_11_8);  // Horizontal Cross
    Run_Tree->SetBranchAddress("ADC_11_9", &ADC_11_9);  // Vertical Cross
    Run_Tree->SetBranchAddress("ADC_11_10", &ADC_11_10);  // Scintilator 1
    Run_Tree->SetBranchAddress("ADC_11_11", &ADC_11_11);  // Scintilator 2
	
    Run_Tree->SetBranchAddress("ADC_14_0", &ADC_14_0);    //Cherenkov Upstream
    Run_Tree->SetBranchAddress("ADC_14_1", &ADC_14_1);    // Cherenkov Downsteam inner
    Run_Tree->SetBranchAddress("ADC_14_2", &ADC_14_2);    // Cherenkov Downstream outer
    Run_Tree->SetBranchAddress("ADC_14_3", &ADC_14_3);
    Run_Tree->SetBranchAddress("ADC_14_4", &ADC_14_4);    
    Run_Tree->SetBranchAddress("ADC_14_5", &ADC_14_5);
    Run_Tree->SetBranchAddress("ADC_14_6", &ADC_14_6);
    Run_Tree->SetBranchAddress("ADC_14_7", &ADC_14_7);
    Run_Tree->SetBranchAddress("ADC_14_8", &ADC_14_8);    
    Run_Tree->SetBranchAddress("ADC_14_9", &ADC_14_9);
    Run_Tree->SetBranchAddress("ADC_14_10", &ADC_14_10);
    Run_Tree->SetBranchAddress("ADC_14_11", &ADC_14_11);
    
	float H_Cross_Min = 160.0;
	float V_Cross_Min = 280.0;
	float SC_1_Min = 130.0;
	float SC_2_Min = 60.0;
    
    
    Int_t nentries_wtn = (Int_t) Run_Tree->GetEntries();
    cout<<"nentries_wtn===="<<nentries_wtn<<"\n";
    for (Int_t i = 0; i < nentries_wtn; i++) {
        Run_Tree->GetEntry(i);
        if (i % 1000 == 0) fprintf(stdout, "\r  Processed events: %8d of %8d ", i, nentries_wtn);
        fflush(stdout);
        
       if( ADC_11_8 > H_Cross_Min && ADC_11_9 > V_Cross_Min && ADC_11_10 > SC_1_Min && ADC_11_11 > SC_2_Min){
		float Tot_Charge = ADC_11_0 + ADC_11_1 + ADC_11_2 + ADC_11_3 + ADC_11_4 + ADC_11_5 + ADC_11_6 + ADC_11_7;
		ChargeSum->Fill(Tot_Charge);
	   }
        
    }
    
    fout->cd();
    ChargeSum->Write();
    fout->Close();
    
    
}


