#define data7tevcode_cxx
#include "data7tevcode.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include<math.h>
#include "TMath.h"
void data7tevcode::Loop()
{
    
TFile *fout=new TFile("Zdata7tevplots.root","RECREATE");
TH1F *histm=new TH1F("histm","invariant mass distribution of Z",500,70,110);

//   In a ROOT session, you can do:
//      root> .L data7tevcode.C
//      root> data7tevcode t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;

   //e for electron
   //p for positron


   //Four vector for electron

   double Pxe[400];       
   double Pye[400];
   double Pze[400];
   double Ee[400];
   double Pte[400];
   double Etae[400];
   double Phie[400];


   //Four vector for positron
   double Pxp[400];
   double Pyp[400];
   double Pzp[400];
   double Ep[400];
   double Ptp[400];
   double Etap[400];
   double Phip[400];

int ce; //counter of e in an event
int cp; //counter of p in an event
int cjet; //counter for jet

double deltaPhie;    //delta phi of e
double deltaPhip;
double deltaEtae;
double deltaEtap;

double deltaPhief;  // delta phi of e within 180 
double deltaPhipf;


double deltaRe;
double deltaRp;
const double pi=TMath::Pi();
double Zmass;

int ne[100]; //selecting electrons under given cuts
int np[100];


TLorentzVector fourPe; //four vector of e

TLorentzVector fourPp; // four vector of p

TLorentzVector fourPZ; // four vector of Z




//*****************************EVENT LOOP**********************************************************************************************************
   for (Long64_t jentry=0; jentry<nentries;jentry++) 
   {
       cout<<jentry<<endl;

      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;

      // if (Cut(ientry) < 0) continue;
  ce=0; //counter of e in an event
  cp=0;//counter of p in an event
      for(int i=0;i<EleCharge->size();i++) //electron loop
      {
            if(EleCharge->at(i)==-1 && ElePt->at(i)>25) // getting e info
            {
                Pxe[i]=ElePx->at(i);
                Pye[i]=ElePy->at(i);
                Pze[i]=ElePz->at(i);
                Pte[i]=ElePt->at(i);
                Ee[i]=EleE->at(i);
                Etae[i]=EleEta->at(i);
                Phie[i]=ElePhi->at(i);
                ne[ce]=i;
                ce++;
            }
            if(EleCharge->at(i)==1 && ElePt->at(i)>25) // getting p info
            {
                Pxp[i]=ElePx->at(i);
                Pyp[i]=ElePy->at(i);
                Pzp[i]=ElePz->at(i);
                Ptp[i]=ElePt->at(i);
                Ep[i]=EleE->at(i);
                Etap[i]=EleEta->at(i);
                Phip[i]=ElePhi->at(i);
                np[cp]=i;
                cp++;
            }
            
            
            
      }//electron loop ends
            
            //one e one p 
            if(ce ==1 && cp ==1)
            {
                    cjet=0;
                    fourPe.SetPxPyPzE(Pxe[ne[0]],Pye[ne[0]],Pze[ne[0]],Ee[ne[0]]);
                    fourPp.SetPxPyPzE(Pxp[np[0]],Pyp[np[0]],Pzp[np[0]],Ep[np[0]]);

            for(int j=0;j<JetPt->size();j++) //jet loop
            {
                
                if(JetPt->at(j)>25) //Pt cut for jet
                {  
                    deltaPhie=Phie[ne[0]] - JetPhi->at(j);
                    deltaEtae=Etae[ne[0]]-JetEta->at(j);
                    
                    deltaPhip=Phip[np[0]] - JetPhi->at(j);
                    deltaEtap=Etap[np[0]]-JetEta->at(j);
                    //phi condition for e
                    if(abs(deltaPhie)<pi)
                    {
                        deltaPhief=abs(deltaPhie);
                    }
                    if(abs(deltaPhie)>=pi)
                    {
                        deltaPhief=2*pi-abs(deltaPhie);
                    }
                    
                    //phi condition for p
                    if(abs(deltaPhip)<pi)
                    {
                        deltaPhipf=abs(deltaPhip);
                    }
                    if(abs(deltaPhip)>=pi)
                    {
                        deltaPhipf=2*pi-abs(deltaPhip);
                    }
               
                deltaRe=sqrt(  pow(deltaPhief,2)+ pow(deltaEtae,2)          );
                deltaRp=  sqrt(  pow(deltaPhipf,2)+ pow(deltaEtap,2)          );
                
                
                
                
                if(deltaRe> 0.4&&deltaRp>0.4)
                    cjet++;
                }
                
                
            }//jet loop ends
            
            if(cjet >=1) //atleast one jet required
            {
                
             fourPZ=fourPe+fourPp;
              Zmass=fourPZ.M();
              
              
              histm->Fill(Zmass);
            }
            } //one e one p loop ends

    





   } //end of event loop
  //*****************************EVENT LOOP ended********************************************************************************************************** 
   
   
   
   histm->Draw();
fout->Write();

   
   
   
   
}//end of program
