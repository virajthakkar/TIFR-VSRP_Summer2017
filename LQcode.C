#define LQcode_cxx
#include "LQcode.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void LQcode::Loop()
{
TFile *fout=new TFile("LQinvmassplot.root","RECREATE");
TH1F *histmLQ=new TH1F("histmLQ","invariant mass distribution of LeptoQuark",100,200,300);
TH1F *histmLQn=new TH1F("histmLQn","norm invariant mass distribution of LeptoQuark",100,200,300);
//   In a ROOT session, you can do:
//      root> .L LQcode.C
//      root> LQcode t
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

   
    
    //Four vector for electron

   double Pxe[400];       
   double Pye[400];
   double Pze[400];
   double Ee[400];
   double Pte[400];
   double Etae[400];
   double Phie[400];

   //Jet information arrays
   
   double JetPx[400];
   double JetPy[400];
   double JetPz[400];
   double JetE[400];
   double JetPt[400];
   double JetEta[400];
   double JetPhi[400];
   
   
   int ce; //counter of e in an event
   int cjet; //counter for jet

   
   int ne[300]; //selecting electrons under given cuts
   int nj[300]; // selecting jets under given cuts
   
   double tempPt;
   double tempPx;
   double tempPy;
   double tempPz;
   double tempE;
   double tempEta;
   double tempPhi;
   
   const double pi=3.1415926535897932384626433832795028;
   
   double deltaR1;
   double deltaR2;
   double deltaR3;
   double deltaR4;
   
   double deltaPhi1;
   double deltaPhi2;
   double deltaPhi3;
   double deltaPhi4;
   
    double deltaPhi1f; //delta phi within 180
   double deltaPhi2f;
   double deltaPhi3f;
   double deltaPhi4f;
   
   double deltaEta1;
   double deltaEta2;
   double deltaEta3;
   double deltaEta4;
   
   
   TLorentzVector Pe1;   //four momentum for first electron
   TLorentzVector Pe2;  //four momentum for second electron
   TLorentzVector Pjet1; //four momentum for first Jet
   TLorentzVector Pjet2; // four momentum for second Jet
   
   
   TLorentzVector LQ1; //four momentum of LeptoQuark 1
   TLorentzVector LQ2; //four momentum of LeptoQuark 2
   TLorentzVector LQ3; //four momentum of LeptoQuark 3
   TLorentzVector LQ4; //four momentum of LeptoQuark 4
   
   
   double mLQ1; // invariant mass of LeptoQuark 1
   double mLQ2; // invariant mass of LeptoQuark 2
   double mLQ3; // invariant mass of LeptoQuark 3
   double mLQ4; // invariant mass of LeptoQuark 4
   
   
   double dm12; // |mLQ1-LQ2|
   double dm34; // |mLQ3-LQ4|

   double avgmLQ12; //average of mLQ1 and mLQ2
   double avgmLQ34; //average of mLQ3 and mLQ4
   
//************************************************EVENT LOOP**************************************************************************************
for (Long64_t jentry=0; jentry<nentries;jentry++) 
   {
       
     //  cout<<jentry<<endl;
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      
      
      ce=0;
       for(int i=0;i<Electron_Px->size();i++) //electron loop
       {
           if(Electron_PtHEEP->at(i)>50) //Pt cut for electron 
           {
                Pxe[i]=Electron_Px->at(i);
                Pye[i]=Electron_Py->at(i);
                Pze[i]=Electron_Pz->at(i);
                Pte[i]=Electron_PtHEEP->at(i);
                Ee[i]=Electron_scEnergy->at(i);
                Etae[i]=Electron_scEta->at(i);
                Phie[i]=Electron_Phi->at(i);
                ne[ce]=i;
                ce++;
          }
           
        }//electron loop ends
      
      cjet=0;
        for(int j=0;j<Jets->size();j++) //jet loop
        {
            if(Jets->at(j).Vect().Pt()>50)
            {
                
                JetPx[j]=Jets->at(j).Px();
                JetPy[j]=Jets->at(j).Py();
                JetPz[j]=Jets->at(j).Pz();
                JetE[j]=Jets->at(j).E();
                JetPt[j]=Jets->at(j).Vect().Pt();
                JetPhi[j]=Jets->at(j).Vect().Phi();
                JetEta[j]=Jets->at(j).Vect().Eta();
                
                nj[cjet]=j;
                cjet++;
            }
            
            
        }//end of jet loop 
      
      if(ce==2&&cjet>=2) //selecting two e event and #jets>=2
      {
          //the two electrons ( e or p,charge is not known) are Pxe[ne[0]] and  Pxe[ne[1]]
          //we have #cjet jets in our event. We have to select two of them with the highest Pt
          
          
          //code for arranging the array JetPt of size #cjet in descending order
           for(int s=0; s<cjet; s++)
            {
                        for(int t=s+1; t<cjet; t++)
                        {
            /*
             * If there is a smaller element towards left of the array then swap it.
             */
                                            if(JetPt[nj[s]] < JetPt[nj[t]])
                                        {
                                        tempPt = JetPt[nj[s]];
                                        JetPt[nj[s]] = JetPt[nj[t]];
                                        JetPt[nj[t]] = tempPt;
                                        
                                        tempPx = JetPx[nj[s]];
                                        JetPx[nj[s]] = JetPx[nj[t]];
                                        JetPx[nj[t]] = tempPx;
                                        
                                        tempPy = JetPy[nj[s]];
                                        JetPy[nj[s]] = JetPy[nj[t]];
                                        JetPy[nj[t]] = tempPy;
                                        
                                        
                                        tempPz = JetPz[nj[s]];
                                        JetPz[nj[s]] = JetPz[nj[t]];
                                        JetPz[nj[t]] = tempPz;
                                        
                                        tempE = JetE[nj[s]];
                                        JetE[nj[s]] = JetE[nj[t]];
                                        JetE[nj[t]] = tempE;
                                        
                                        tempPhi = JetPhi[nj[s]];
                                        JetPhi[nj[s]] = JetPhi[nj[t]];
                                        JetPhi[nj[t]] = tempPhi;
                                        
                                        tempEta = JetEta[nj[s]];
                                        JetEta[nj[s]] = JetEta[nj[t]];
                                        JetEta[nj[t]] = tempEta;

                                        }
                        }
            }// end of arrranging in descending order 
            
 //So now the two jets with the highest Pt are JetPt[nj[0]] and JetPt[nj[1]] respectively  // JetPt[nj[0]]>JetPt[nj[1]]
          //the two electrons ( e or p,charge is not known) are Pxe[ne[0]] and  Pxe[ne[1]]
          
          //deltaR1 is delta R between 1st electron and 1st Jet
          //deltaR2 is delta R between 1st electron and 2nd Jet
          //deltaR3 is delta R between 2nd electron and 1st Jet
          //deltaR4 is delta R between 2nd electron and 2nd Jet
          
                    deltaPhi1=Phie[ne[0]] - JetPhi[nj[0]];
                    deltaEta1=Etae[ne[0]]-JetEta[nj[0]];
                    
                 //phi condition for e1 j1
                    if(abs(deltaPhi1)<pi)
                    {
                        deltaPhi1f=abs(deltaPhi1);
                    }
                    if(abs(deltaPhi1)>=pi)
                    {
                        deltaPhi1f=2*pi-abs(deltaPhi1);
                    }
                         deltaR1=sqrt(  pow(deltaPhi1f,2)+ pow(deltaEta1,2)          );
                    
                         
                         
                    deltaPhi2=Phie[ne[0]] - JetPhi[nj[1]];
                    deltaEta2=Etae[ne[0]]-JetEta[nj[1]];
                    
                    //phi condition for e1 j2
                    if(abs(deltaPhi2)<pi)
                    {
                        deltaPhi2f=abs(deltaPhi2);
                    }
                    if(abs(deltaPhi2)>=pi)
                    {
                        deltaPhi2f=2*pi-abs(deltaPhi2);
                    }
                    
                    deltaR2=sqrt(  pow(deltaPhi2f,2)+ pow(deltaEta2,2)          );
                    
                    
                    
                    deltaPhi3=Phie[ne[1]] - JetPhi[nj[0]];
                    deltaEta3=Etae[ne[1]]-JetEta[nj[0]];
                    
                 //phi condition for e2 j1
                    if(abs(deltaPhi3)<pi)
                    {
                        deltaPhi3f=abs(deltaPhi3);
                    }
                    if(abs(deltaPhi3)>=pi)
                    {
                        deltaPhi3f=2*pi-abs(deltaPhi3);
                    }
                         deltaR3=sqrt(  pow(deltaPhi3f,2)+ pow(deltaEta3,2)          );
                    
                    
                         
                    deltaPhi4=Phie[ne[1]] - JetPhi[nj[1]];
                    deltaEta4=Etae[ne[1]]-JetEta[nj[1]];
                    
                 //phi condition for e2 j2
                    if(abs(deltaPhi4)<pi)
                    {
                        deltaPhi4f=abs(deltaPhi4);
                    }
                    if(abs(deltaPhi4)>=pi)
                    {
                        deltaPhi4f=2*pi-abs(deltaPhi4);
                    }
                         deltaR4=sqrt(  pow(deltaPhi4f,2)+ pow(deltaEta4,2)          );
                         
                         
                         
                         if(deltaR1>0.4&&deltaR2>0.4&&deltaR3>0.4&&deltaR4>0.4)
                         {
                           //  cout<<"yes"<<endl;
                             Pe1.SetPxPyPzE(Pxe[ne[0]],Pye[ne[0]],Pze[ne[0]],Ee[ne[0]]);
                             Pe2.SetPxPyPzE(Pxe[ne[1]],Pye[ne[1]],Pze[ne[1]],Ee[ne[1]]);
                             Pjet1.SetPxPyPzE(JetPx[nj[0]],JetPy[nj[0]],JetPz[nj[0]],JetE[nj[0]]);
                             Pjet2.SetPxPyPzE(JetPx[nj[1]],JetPy[nj[1]],JetPz[nj[1]],JetE[nj[1]]);
                             
                             // Combination e1jet1 (LQ1)   and  e2jet2 ( LQ2)
                             LQ1=Pe1+Pjet1;
                             mLQ1=LQ1.M();
                             
                             LQ2=Pe2+Pjet2;
                             mLQ2=LQ2.M();
                             
                             dm12=abs(mLQ1-mLQ2);
                             
                             // Combination e1jet2 (LQ3)   and  e2jet1 ( LQ4)
                             LQ3=Pe1+Pjet2;
                             mLQ3=LQ3.M();
                             
                             LQ4=Pe2+Pjet1;
                             mLQ4=LQ4.M();
                             
                             dm34=abs(mLQ3-mLQ4);
                             
                             
                             //average masses
                             avgmLQ12=0.5*(mLQ1+mLQ2);
                             avgmLQ34=0.5*(mLQ3+mLQ4);
                             
                             if(dm12>=dm34) //fill histogram
                             {
                            histmLQ->Fill(avgmLQ34);
                                                            histmLQn->Fill(avgmLQ34);

                            }
                            if(dm34>dm12)
                            {
                                histmLQ->Fill(avgmLQ12);
                                histmLQn->Fill(avgmLQ12);
                            }
                             
                             
                          }
                    
                    
          
    } //end of selecting two e event and #jets>=2
      
      
      
      
      
      
      
   }
//**********************************************************end of event loop**********************************************************   
    double cxn=60000; // fb
    double lumi=36; //fb-1
      cout<<histmLQ->Integral()<<endl;
      cout<<histmLQn->Integral()<<endl;
    double  scale =(cxn*lumi)/50000;
    
    histmLQn->Scale(scale);
    histmLQ->Draw();
    //histmLQn->DrawNormalized();
  
fout->Write();

}//__________________________________end of program_________________________________
