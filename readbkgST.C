#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include<math.h>

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>


void readbkgST()
{
    
     int uplimit;
    double lowlimit;
    double factor;
ifstream fin;
  fin.open("limitsST.txt",ios::in);
 
    fin>>uplimit;
    fin>>lowlimit;
    fin>>factor;
    //cout<<uplimit<<endl;
//cout<<lowlimit<<endl;
//cout<<factor<<endl;
    
    //      inc=lowlimit + t*factor;
    
    
    double lim1;
    double lim2;
    ifstream fin2;
fin2.open("otherlimits.txt",ios::in);    
    fin2>>lim1;
    fin2>>lim2;
    //cout<<lim1<<endl;
    //cout<<lim2<<endl;
    
    
     ofstream textout;
textout.open(Form("Opt_ST_for_Mee>%.0lf_Mej>%.0lf.txt",lim1,lim2));
textout.precision(10);
//file.setf(ios::scientific);
textout.setf(ios::showpoint);
    
    textout<<" Mee> "<<lim1<<" Mej>  "<<lim2<<endl;

    
    
    //Define arrays to store Integral of histograms
    int nintDY[uplimit];
    int nintGjets200400[uplimit];
    int nintGjets400600[uplimit];
    int nintGjets600inf[uplimit];
    int nintSTAntitopTChannel[uplimit];
    int nintSTAntitopWChannel[uplimit];
    int nintSTTopTChannel[uplimit];
    int nintSTTopWChannel[uplimit];
    int nintTTbar[uplimit];
    int nintWW[uplimit];
    int nintWZ[uplimit];
    int nintZZ[uplimit];
      
    int nintsigLQ250[uplimit];       //signal
    
    int totbkg[uplimit]; //summation of background
    double  optratio[uplimit];
    
    double inc[uplimit]; // means ST> inc
    
    TFile *fDYST_pt =new  TFile("DY_pt_plots.root","READ");
    TFile *fGJets200_400_pt=new  TFile("GJets200_400_pt_plots.root","READ");
    TFile *fGJets400_600_pt =new  TFile("GJets400_600_pt_plots.root","READ");
    TFile *fGJets600_inf_pt =new  TFile("GJets600_inf_pt_plots.root","READ");
    TFile *fsigLQ250_pt =new  TFile("sigLQ250_pt_plots.root","READ");                        //Signal 
    TFile *fST_Antitop_T_Channel_pt =new  TFile("ST_Antitop_T_Channel_pt_plots.root","READ");
    TFile *fST_Antitop_W_Channel_pt =new  TFile("ST_Antitop_W_Channel_pt_plots.root","READ");
    TFile *fST_Top_T_Channel_pt =new  TFile("ST_Top_T_Channel_pt_plots.root","READ");
    TFile *fST_Top_W_Channel_pt =new  TFile("ST_Top_W_Channel_pt_plots.root","READ");
    TFile *fTTbar_pt =new  TFile("TTbar_pt_plots.root","READ");
    TFile *fWW_pt =new  TFile("WW_pt_plots.root","READ");
    TFile *fWZ_pt =new  TFile("WZ_pt_plots.root","READ");
    TFile *fZZ_pt=new  TFile("ZZ_pt_plots.root","READ");
     //f->ls{};
     
    
char Name1pt[uplimit];
TH1F *hDYSTpt[uplimit];
for(int i=0;i<uplimit;i++){
sprintf(Name1pt,"hDYST_pt%i",i);
hDYSTpt[i]=(TH1F*)fDYST_pt->Get(Name1pt);
}

char Name2pt[uplimit];
TH1F *hGJets200_400STpt[uplimit];
for(int i=0;i<uplimit;i++){
sprintf(Name2pt,"GJets200_400ST_pt%i",i);
hGJets200_400STpt[i]=(TH1F*)fGJets200_400_pt->Get(Name2pt);
}

char Name3pt[uplimit];
TH1F *hGJets400600STpt[uplimit];
for(int i=0;i<uplimit;i++){
sprintf(Name3pt,"GJets400600ST_pt%i",i);
hGJets400600STpt[i]=(TH1F*)fGJets400_600_pt->Get(Name3pt);
}

char Name4pt[uplimit];
TH1F *hGJets600_infSTpt[uplimit];
for(int i=0;i<uplimit;i++){
sprintf(Name4pt,"GJets600_infST_pt%i",i);
hGJets600_infSTpt[i]=(TH1F*)fGJets600_inf_pt->Get(Name4pt);
}

char Name5pt[uplimit];
TH1F *hST_Antitop_T_ChannelSTpt[uplimit];
for(int i=0;i<uplimit;i++){
sprintf(Name5pt,"ST_Antitop_T_ChannelST_pt%i",i);
hST_Antitop_T_ChannelSTpt[i]=(TH1F*)fST_Antitop_T_Channel_pt->Get(Name5pt);
}

char Name6pt[uplimit];
TH1F *hST_Antitop_W_ChannelSTpt[uplimit];
for(int i=0;i<uplimit;i++){
sprintf(Name6pt,"ST_Antitop_W_ChannelST_pt%i",i);
hST_Antitop_W_ChannelSTpt[i]=(TH1F*)fST_Antitop_W_Channel_pt->Get(Name6pt);
}

char Name7pt[uplimit];
TH1F *hST_Top_T_ChannelSTpt[uplimit];
for(int i=0;i<uplimit;i++){
sprintf(Name7pt,"ST_Top_T_ChannelST_pt%i",i);
hST_Top_T_ChannelSTpt[i]=(TH1F*)fST_Top_T_Channel_pt->Get(Name7pt);
}

char Name8pt[uplimit];
TH1F *hST_Top_W_ChannelSTpt[uplimit];
for(int i=0;i<uplimit;i++){
sprintf(Name8pt,"ST_Top_W_ChannelST_pt%i",i);
hST_Top_W_ChannelSTpt[i]=(TH1F*)fST_Top_W_Channel_pt->Get(Name8pt);
}

char Name9pt[uplimit];
TH1F *hTTbarSTpt[uplimit];
for(int i=0;i<uplimit;i++){
sprintf(Name9pt,"hTTbarST_pt%i",i);
hTTbarSTpt[i]=(TH1F*)fTTbar_pt->Get(Name9pt);
}

char Name10pt[uplimit];
TH1F *hWW_STpt[uplimit];
for(int i=0;i<uplimit;i++){
sprintf(Name10pt,"WW_ST_pt%i",i);
hWW_STpt[i]=(TH1F*)fWW_pt->Get(Name10pt);
}

char Name11pt[uplimit];
TH1F *hWZ_STpt[uplimit];
for(int i=0;i<uplimit;i++){
sprintf(Name11pt,"WZ_ST_pt%i",i);
hWZ_STpt[i]=(TH1F*)fWZ_pt->Get(Name11pt);
}

char Name12pt[uplimit];
TH1F *hZZ_STpt[uplimit];
for(int i=0;i<uplimit;i++){
sprintf(Name12pt,"ZZ_ST_pt%i",i);
hZZ_STpt[i]=(TH1F*)fZZ_pt->Get(Name12pt);
}

char Name13pt[uplimit];
TH1F *hLQ250pt[uplimit];
for(int i=0;i<uplimit;i++){
sprintf(Name13pt,"hLQ250_pt%i",i);
hLQ250pt[i]=(TH1F*)fsigLQ250_pt->Get(Name13pt);
}
 double eroptratio[uplimit];
 for(int i=0;i<uplimit;i++){eroptratio[i]=0;} //error in optratio
 
 double erinc[uplimit];
 for(int i=0;i<uplimit;i++){erinc[i]=0;} //error in erinc
 

     
  // c1 = new TCanvas("c1","A Simple Graph with error bars",200,10,700,500);
  TFile *fgraph=new TFile("Optratio_vs_incST.root","RECREATE");
 //TGraphErrors *graph_Opt = new TGraphErrors(uplimit,optratio,inc,eroptratio,erinc);
// TGraph *graph_Opt = new TGraph(uplimit,optratio,inc);
    
      //c1->SetCanvasSize(500, 500);

     // TH2D *hKpPim=(TH2D*)f->Get("K+Pi-");
//hTTbarSTpt[0]->Draw();
   
  // cout<<"integral 0 "<<hTTbarSTpt[0]->Integral()<<endl;
    //cout<<"integral 1 "<<hTTbarSTpt[1]->Integral()<<endl;
    
    for(int m=0;m<uplimit;m++) //Looping over all the uplimit histograms
      {
          
          nintDY[m]=hDYSTpt[m]->Integral();
          nintGjets200400[m]=hGJets200_400STpt[m]->Integral();
          nintGjets400600[m]=hGJets400600STpt[m]->Integral();
          nintGjets600inf[m]=hGJets600_infSTpt[m]->Integral();
          nintSTAntitopTChannel[m]=hST_Antitop_T_ChannelSTpt[m]->Integral();
          nintSTAntitopWChannel[m]=hST_Antitop_W_ChannelSTpt[m]->Integral();
          nintSTTopTChannel[m]=hST_Top_T_ChannelSTpt[m]->Integral();
          nintSTTopWChannel[m]=hST_Top_W_ChannelSTpt[m]->Integral();
          nintTTbar[m]=hTTbarSTpt[m]->Integral();
          nintWW[m]=hWW_STpt[m]->Integral();
          nintWZ[m]=hWZ_STpt[m]->Integral();
          nintZZ[m]=hZZ_STpt[m]->Integral();
         
          nintsigLQ250[m]=hLQ250pt[m]->Integral();  //signal
        
         totbkg[m]= nintDY[m]+nintGjets200400[m] + nintGjets400600[m]  +  nintGjets600inf[m] + nintSTAntitopTChannel[m] + nintSTAntitopWChannel[m] + nintTTbar[m] +  nintWW[m] +  nintWZ[m]  + nintZZ[m];
         
         
         optratio[m]=(nintsigLQ250[m])/(pow(totbkg[m],0.5));
        //cout<<nintTTbar[m]<<endl;
        
          inc[m]=lowlimit + m*factor;;
         
          
            
      //   cout<<setw(15)<<nintsigLQ250[m]<<setw(15)<<(pow(totbkg[m],0.5))<<setw(15)<<optratio[m]<<"     "<<inc[m]<<endl;
             cout<<setw(20)<<nintsigLQ250[m]<<setw(20)<<(pow(totbkg[m],0.5))<<setw(20)<<optratio[m]<<setw(20)<<inc[m]<<endl;
         textout<<setw(20)<<nintsigLQ250[m]<<setw(20)<<(pow(totbkg[m],0.5))<<setw(20)<<optratio[m]<<setw(20)<<inc[m]<<endl;
        } 
       // TGraph *graph_Opt = new TGraph(uplimit,,inc);
         TCanvas *c = new TCanvas("c", "graph of Opt ratio vs ST", 200, 10,600,400);
        TGraph *graph_Opt = new TGraph(uplimit,inc,optratio);
        
         c->SetLeftMargin(0.2);
  c->SetRightMargin(0.05);
  c->SetTopMargin(0.09);
  c->SetBottomMargin(0.13);
  graph_Opt->SetTitle(Form("Optimization ratio vs S_{T} for M_{ee}> %.2lf and M_{ej}> %.2lf",lim1,lim2));
  //graph_Opt->SetMaximum(0.905);
  //graph_Opt->SetMinimum(0.89);
  graph_Opt->SetMarkerColor(1);
  graph_Opt->SetMarkerStyle(20);
  graph_Opt->SetMarkerSize(1.0);
  graph_Opt->GetXaxis()->SetTitle("S_{T} (GeV/c^{2})");
  graph_Opt->GetXaxis()->SetTitleSize(0.05);
  graph_Opt->GetXaxis()->SetTitleOffset(1.);
  graph_Opt->GetXaxis()->SetTitleFont(42);
  graph_Opt->GetXaxis()->CenterTitle(true);
  graph_Opt->GetXaxis()->SetLabelSize(0.05);
  graph_Opt->GetXaxis()->SetLabelFont(42);
 // graph_Opt->GetXaxis()->SetNdivisions(505);
  graph_Opt->GetYaxis()->SetTitle("s/#sqrt{b} ");
  graph_Opt->GetYaxis()->SetTitleFont(42);
  graph_Opt->GetYaxis()->CenterTitle(true);
  graph_Opt->GetYaxis()->SetTitleSize(0.05);
  graph_Opt->GetYaxis()->SetTitleOffset(1.);
  graph_Opt->GetYaxis()->SetLabelSize(0.05);
  graph_Opt->GetYaxis()->SetLabelFont(42);
 // graph_Opt->GetYaxis()->SetNdivisions(505);
  //graph_Opt->Draw("AP");
    graph_Opt->Draw("AC*");

 c->SaveAs(Form("Optratio_vs_ST_LQ250_Mee>%.0lf_Mej>%.0lf.gif",lim1,lim2));
  c->SaveAs(Form("Optratio_vs_ST_LQ250_Mee>%.0lf_Mej>%.0lf.png",lim1,lim2));
  c->SaveAs(Form("Optratio_vs_ST_LQ250_Mee>%.0lf_Mej>%.0lf.pdf",lim1,lim2));
  c->SaveAs(Form("Optratio_vs_ST_LQ250_Mee>%.0lf_Mej>%.0lf.eps",lim1,lim2));
  c->SaveAs(Form("Optratio_vs_ST_LQ250_Mee>%.0lf_Mej>%.0lf.C",lim1,lim2));
  c->cd();
       fgraph->Write();  
     
        
         double temp1,temp2;
    for(int s=0; s<uplimit; s++)
            {
                        for(int t=s+1; t<uplimit; t++)
                        {
            /*
             * If there is a smaller element towards left of the array then swap it.
             */
                                            if(optratio[s] < optratio[t])
                                        {
                                        temp1= optratio[s];
                                        optratio[s] = optratio[t];
                                        optratio[t] = temp1;
                                        
                                        temp2=inc[s];
                                        inc[s]=inc[t];
                                        inc[t]=temp2;
                                        }
                                        
                        }
            }
            cout<<"Max opt ratio is  "<<optratio[0]<<"  at   "<<inc[0]<<endl;
            textout<<"Max opt ratio is  "<<optratio[0]<<"  at   "<<inc[0]<<endl;
            
        
       
       
        //double  xTemp, yTemp;
        //std::cout << "*** " << graph_Opt->GetPoint(5, xTemp, yTemp) << "\n";
        //std::cout << xTemp << " " << yTemp << "\n";

       
}
