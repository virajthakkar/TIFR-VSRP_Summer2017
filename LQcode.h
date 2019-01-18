//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu May 25 19:05:30 2017 by ROOT version 6.08/04
// from TTree SimpleTree/SimpleTree
// found on file: Summer16.LQToUE_M-250_BetaOne_TuneCUETP8M1_13TeV-pythia8_0.root
//////////////////////////////////////////////////////////

#ifndef LQcode_h
#define LQcode_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"
#include "vector"
#include "vector"

class LQcode {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   UInt_t          RunNum;
   UInt_t          LumiBlockNum;
   ULong64_t       EvtNum;
   Bool_t          BadChargedCandidateFilter;
   Bool_t          BadPFMuonFilter;
   Double_t        CaloMET;
   Double_t        CaloMETPhi;
   vector<double>  *ColumnNum;
   Double_t        CrossSection;
   Int_t           CSCTightHaloFilter;
   vector<double>  *dxy;
   Int_t           EcalDeadCellTriggerPrimitiveFilter;
   Int_t           eeBadScFilter;
   vector<int>     *Electron_Charge;
   vector<double>  *Electron_DeltaEtain;
   vector<double>  *Electron_DeltaEtaSeed;
   vector<double>  *Electron_DeltaPhiin;
   vector<double>  *Electron_e15bye55;
   vector<double>  *Electron_e25bye55;
   vector<bool>    *Electron_ecalDriven;
   vector<double>  *Electron_ecalEnergy;
   vector<double>  *Electron_Ecaliso;
   vector<double>  *Electron_Energy;
   vector<double>  *Electron_Et;
   vector<double>  *Electron_full55SiEtaiEta;
   vector<double>  *Electron_Fulle15bye55;
   vector<double>  *Electron_Fullsce25bye55;
   vector<double>  *Electron_HD1iso;
   vector<double>  *Electron_heep70TrkIso;
   vector<double>  *Electron_HOverE;
   vector<int>     *Electron_losthits;
   vector<bool>    *Electron_passEcaldriven;
   vector<bool>    *Electron_passEMHD1iso;
   vector<bool>    *Electron_passN1TrkIso;
   vector<double>  *Electron_Phi;
   vector<double>  *Electron_PtHEEP;
   vector<double>  *Electron_Px;
   vector<double>  *Electron_Py;
   vector<double>  *Electron_Pz;
   vector<double>  *Electron_sce25bye55;
   vector<double>  *Electron_scEnergy;
   vector<double>  *Electron_scEta;
   vector<double>  *Electron_trackiso;
   vector<int>     *elstatus;
   vector<int>     *gencharge;
   vector<double>  *genEnergy;
   vector<double>  *genEta;
   Double_t        GenHT;
   vector<TLorentzVector> *GenJets;
   vector<bool>    *GenJets_HTMask;
   vector<bool>    *GenJets_MHTMask;
   Double_t        GenMET;
   Double_t        GenMETPhi;
   vector<double>  *genPhi;
   vector<double>  *genPt;
   Int_t           globalTightHalo2016Filter;
   Int_t           HBHEIsoNoiseFilter;
   Int_t           HBHENoiseFilter;
   Bool_t          JetID;
   Bool_t          JetIDJECdown;
   Bool_t          JetIDJECup;
   Bool_t          JetIDJERdown;
   Bool_t          JetIDJERup;
   vector<TLorentzVector> *Jets;
   vector<bool>    *Jets_ID;
   vector<TLorentzVector> *JetsJECdown;
   vector<bool>    *JetsJECdown_ID;
   vector<TLorentzVector> *JetsJECup;
   vector<bool>    *JetsJECup_ID;
   vector<TLorentzVector> *JetsJERdown;
   vector<bool>    *JetsJERdown_ID;
   vector<TLorentzVector> *JetsJERup;
   vector<bool>    *JetsJERup_ID;
   Double_t        madHT;
   Double_t        MET;
   vector<double>  *METDown;
   Double_t        METPhi;
   vector<double>  *METPhiDown;
   vector<double>  *METPhiUp;
   vector<double>  *METUp;
   vector<int>     *motherPDGID;
   vector<double>  *MuonEnergy;
   vector<double>  *MuonEta;
   vector<int>     *MuonIsGlobal;
   vector<int>     *MuonPassID;
   vector<double>  *MuonPhi;
   vector<double>  *MuonPt;
   Int_t           nAllVertices;
   Double_t        NumEvents;
   Int_t           NumInteractions;
   Int_t           NVtx;
   vector<double>  *objectE;
   vector<double>  *objecteta;
   vector<double>  *objectphi;
   vector<double>  *objectPt;
   vector<int>     *PDFids;
   vector<double>  *PDFweights;
   vector<int>     *PDGID;
   Double_t        PFCaloMETRatio;
   Double_t        puSysDown;
   Double_t        puSysUp;
   Double_t        puWeight;
   vector<double>  *rho;
   vector<double>  *ScaleWeights;
   vector<double>  *TauEta;
   vector<double>  *TauPhi;
   vector<double>  *TauPt;
   vector<string>  *TriggerNames;
   vector<int>     *TriggerPass;
   vector<int>     *TriggerPrescales;
   Double_t        TrueNumInteractions;
   Double_t        Weight;

   // List of branches
   TBranch        *b_RunNum;   //!
   TBranch        *b_LumiBlockNum;   //!
   TBranch        *b_EvtNum;   //!
   TBranch        *b_BadChargedCandidateFilter;   //!
   TBranch        *b_BadPFMuonFilter;   //!
   TBranch        *b_CaloMET;   //!
   TBranch        *b_CaloMETPhi;   //!
   TBranch        *b_ColumnNum;   //!
   TBranch        *b_CrossSection;   //!
   TBranch        *b_CSCTightHaloFilter;   //!
   TBranch        *b_dxy;   //!
   TBranch        *b_EcalDeadCellTriggerPrimitiveFilter;   //!
   TBranch        *b_eeBadScFilter;   //!
   TBranch        *b_Electron_Charge;   //!
   TBranch        *b_Electron_DeltaEtain;   //!
   TBranch        *b_Electron_DeltaEtaSeed;   //!
   TBranch        *b_Electron_DeltaPhiin;   //!
   TBranch        *b_Electron_e15bye55;   //!
   TBranch        *b_Electron_e25bye55;   //!
   TBranch        *b_Electron_ecalDriven;   //!
   TBranch        *b_Electron_ecalEnergy;   //!
   TBranch        *b_Electron_Ecaliso;   //!
   TBranch        *b_Electron_Energy;   //!
   TBranch        *b_Electron_Et;   //!
   TBranch        *b_Electron_full55SiEtaiEta;   //!
   TBranch        *b_Electron_Fulle15bye55;   //!
   TBranch        *b_Electron_Fullsce25bye55;   //!
   TBranch        *b_Electron_HD1iso;   //!
   TBranch        *b_Electron_heep70TrkIso;   //!
   TBranch        *b_Electron_HOverE;   //!
   TBranch        *b_Electron_losthits;   //!
   TBranch        *b_Electron_passEcaldriven;   //!
   TBranch        *b_Electron_passEMHD1iso;   //!
   TBranch        *b_Electron_passN1TrkIso;   //!
   TBranch        *b_Electron_Phi;   //!
   TBranch        *b_Electron_PtHEEP;   //!
   TBranch        *b_Electron_Px;   //!
   TBranch        *b_Electron_Py;   //!
   TBranch        *b_Electron_Pz;   //!
   TBranch        *b_Electron_sce25bye55;   //!
   TBranch        *b_Electron_scEnergy;   //!
   TBranch        *b_Electron_scEta;   //!
   TBranch        *b_Electron_trackiso;   //!
   TBranch        *b_elstatus;   //!
   TBranch        *b_gencharge;   //!
   TBranch        *b_genEnergy;   //!
   TBranch        *b_genEta;   //!
   TBranch        *b_GenHT;   //!
   TBranch        *b_GenJets;   //!
   TBranch        *b_GenJets_HTMask;   //!
   TBranch        *b_GenJets_MHTMask;   //!
   TBranch        *b_GenMET;   //!
   TBranch        *b_GenMETPhi;   //!
   TBranch        *b_genPhi;   //!
   TBranch        *b_genPt;   //!
   TBranch        *b_globalTightHalo2016Filter;   //!
   TBranch        *b_HBHEIsoNoiseFilter;   //!
   TBranch        *b_HBHENoiseFilter;   //!
   TBranch        *b_JetID;   //!
   TBranch        *b_JetIDJECdown;   //!
   TBranch        *b_JetIDJECup;   //!
   TBranch        *b_JetIDJERdown;   //!
   TBranch        *b_JetIDJERup;   //!
   TBranch        *b_Jets;   //!
   TBranch        *b_Jets_ID;   //!
   TBranch        *b_JetsJECdown;   //!
   TBranch        *b_JetsJECdown_ID;   //!
   TBranch        *b_JetsJECup;   //!
   TBranch        *b_JetsJECup_ID;   //!
   TBranch        *b_JetsJERdown;   //!
   TBranch        *b_JetsJERdown_ID;   //!
   TBranch        *b_JetsJERup;   //!
   TBranch        *b_JetsJERup_ID;   //!
   TBranch        *b_madHT;   //!
   TBranch        *b_MET;   //!
   TBranch        *b_METDown;   //!
   TBranch        *b_METPhi;   //!
   TBranch        *b_METPhiDown;   //!
   TBranch        *b_METPhiUp;   //!
   TBranch        *b_METUp;   //!
   TBranch        *b_motherPDGID;   //!
   TBranch        *b_MuonEnergy;   //!
   TBranch        *b_MuonEta;   //!
   TBranch        *b_MuonIsGlobal;   //!
   TBranch        *b_MuonPassID;   //!
   TBranch        *b_MuonPhi;   //!
   TBranch        *b_MuonPt;   //!
   TBranch        *b_nAllVertices;   //!
   TBranch        *b_NumEvents;   //!
   TBranch        *b_NumInteractions;   //!
   TBranch        *b_NVtx;   //!
   TBranch        *b_objectE;   //!
   TBranch        *b_objecteta;   //!
   TBranch        *b_objectphi;   //!
   TBranch        *b_objectPt;   //!
   TBranch        *b_PDFids;   //!
   TBranch        *b_PDFweights;   //!
   TBranch        *b_PDGID;   //!
   TBranch        *b_PFCaloMETRatio;   //!
   TBranch        *b_puSysDown;   //!
   TBranch        *b_puSysUp;   //!
   TBranch        *b_puWeight;   //!
   TBranch        *b_rho;   //!
   TBranch        *b_ScaleWeights;   //!
   TBranch        *b_TauEta;   //!
   TBranch        *b_TauPhi;   //!
   TBranch        *b_TauPt;   //!
   TBranch        *b_TriggerNames;   //!
   TBranch        *b_TriggerPass;   //!
   TBranch        *b_TriggerPrescales;   //!
   TBranch        *b_TrueNumInteractions;   //!
   TBranch        *b_Weight;   //!

   LQcode(TTree *tree=0);
   virtual ~LQcode();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef LQcode_cxx
LQcode::LQcode(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("Summer16.LQToUE_M-250_BetaOne_TuneCUETP8M1_13TeV-pythia8_0.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("Summer16.LQToUE_M-250_BetaOne_TuneCUETP8M1_13TeV-pythia8_0.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("Summer16.LQToUE_M-250_BetaOne_TuneCUETP8M1_13TeV-pythia8_0.root:/LQTreeMaker2");
      dir->GetObject("SimpleTree",tree);

   }
   Init(tree);
}

LQcode::~LQcode()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t LQcode::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t LQcode::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void LQcode::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   ColumnNum = 0;
   dxy = 0;
   Electron_Charge = 0;
   Electron_DeltaEtain = 0;
   Electron_DeltaEtaSeed = 0;
   Electron_DeltaPhiin = 0;
   Electron_e15bye55 = 0;
   Electron_e25bye55 = 0;
   Electron_ecalDriven = 0;
   Electron_ecalEnergy = 0;
   Electron_Ecaliso = 0;
   Electron_Energy = 0;
   Electron_Et = 0;
   Electron_full55SiEtaiEta = 0;
   Electron_Fulle15bye55 = 0;
   Electron_Fullsce25bye55 = 0;
   Electron_HD1iso = 0;
   Electron_heep70TrkIso = 0;
   Electron_HOverE = 0;
   Electron_losthits = 0;
   Electron_passEcaldriven = 0;
   Electron_passEMHD1iso = 0;
   Electron_passN1TrkIso = 0;
   Electron_Phi = 0;
   Electron_PtHEEP = 0;
   Electron_Px = 0;
   Electron_Py = 0;
   Electron_Pz = 0;
   Electron_sce25bye55 = 0;
   Electron_scEnergy = 0;
   Electron_scEta = 0;
   Electron_trackiso = 0;
   elstatus = 0;
   gencharge = 0;
   genEnergy = 0;
   genEta = 0;
   GenJets = 0;
   GenJets_HTMask = 0;
   GenJets_MHTMask = 0;
   genPhi = 0;
   genPt = 0;
   Jets = 0;
   Jets_ID = 0;
   JetsJECdown = 0;
   JetsJECdown_ID = 0;
   JetsJECup = 0;
   JetsJECup_ID = 0;
   JetsJERdown = 0;
   JetsJERdown_ID = 0;
   JetsJERup = 0;
   JetsJERup_ID = 0;
   METDown = 0;
   METPhiDown = 0;
   METPhiUp = 0;
   METUp = 0;
   motherPDGID = 0;
   MuonEnergy = 0;
   MuonEta = 0;
   MuonIsGlobal = 0;
   MuonPassID = 0;
   MuonPhi = 0;
   MuonPt = 0;
   objectE = 0;
   objecteta = 0;
   objectphi = 0;
   objectPt = 0;
   PDFids = 0;
   PDFweights = 0;
   PDGID = 0;
   rho = 0;
   ScaleWeights = 0;
   TauEta = 0;
   TauPhi = 0;
   TauPt = 0;
   TriggerNames = 0;
   TriggerPass = 0;
   TriggerPrescales = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("RunNum", &RunNum, &b_RunNum);
   fChain->SetBranchAddress("LumiBlockNum", &LumiBlockNum, &b_LumiBlockNum);
   fChain->SetBranchAddress("EvtNum", &EvtNum, &b_EvtNum);
   fChain->SetBranchAddress("BadChargedCandidateFilter", &BadChargedCandidateFilter, &b_BadChargedCandidateFilter);
   fChain->SetBranchAddress("BadPFMuonFilter", &BadPFMuonFilter, &b_BadPFMuonFilter);
   fChain->SetBranchAddress("CaloMET", &CaloMET, &b_CaloMET);
   fChain->SetBranchAddress("CaloMETPhi", &CaloMETPhi, &b_CaloMETPhi);
   fChain->SetBranchAddress("ColumnNum", &ColumnNum, &b_ColumnNum);
   fChain->SetBranchAddress("CrossSection", &CrossSection, &b_CrossSection);
   fChain->SetBranchAddress("CSCTightHaloFilter", &CSCTightHaloFilter, &b_CSCTightHaloFilter);
   fChain->SetBranchAddress("dxy", &dxy, &b_dxy);
   fChain->SetBranchAddress("EcalDeadCellTriggerPrimitiveFilter", &EcalDeadCellTriggerPrimitiveFilter, &b_EcalDeadCellTriggerPrimitiveFilter);
   fChain->SetBranchAddress("eeBadScFilter", &eeBadScFilter, &b_eeBadScFilter);
   fChain->SetBranchAddress("Electron_Charge", &Electron_Charge, &b_Electron_Charge);
   fChain->SetBranchAddress("Electron_DeltaEtain", &Electron_DeltaEtain, &b_Electron_DeltaEtain);
   fChain->SetBranchAddress("Electron_DeltaEtaSeed", &Electron_DeltaEtaSeed, &b_Electron_DeltaEtaSeed);
   fChain->SetBranchAddress("Electron_DeltaPhiin", &Electron_DeltaPhiin, &b_Electron_DeltaPhiin);
   fChain->SetBranchAddress("Electron_e15bye55", &Electron_e15bye55, &b_Electron_e15bye55);
   fChain->SetBranchAddress("Electron_e25bye55", &Electron_e25bye55, &b_Electron_e25bye55);
   fChain->SetBranchAddress("Electron_ecalDriven", &Electron_ecalDriven, &b_Electron_ecalDriven);
   fChain->SetBranchAddress("Electron_ecalEnergy", &Electron_ecalEnergy, &b_Electron_ecalEnergy);
   fChain->SetBranchAddress("Electron_Ecaliso", &Electron_Ecaliso, &b_Electron_Ecaliso);
   fChain->SetBranchAddress("Electron_Energy", &Electron_Energy, &b_Electron_Energy);
   fChain->SetBranchAddress("Electron_Et", &Electron_Et, &b_Electron_Et);
   fChain->SetBranchAddress("Electron_full55SiEtaiEta", &Electron_full55SiEtaiEta, &b_Electron_full55SiEtaiEta);
   fChain->SetBranchAddress("Electron_Fulle15bye55", &Electron_Fulle15bye55, &b_Electron_Fulle15bye55);
   fChain->SetBranchAddress("Electron_Fullsce25bye55", &Electron_Fullsce25bye55, &b_Electron_Fullsce25bye55);
   fChain->SetBranchAddress("Electron_HD1iso", &Electron_HD1iso, &b_Electron_HD1iso);
   fChain->SetBranchAddress("Electron_heep70TrkIso", &Electron_heep70TrkIso, &b_Electron_heep70TrkIso);
   fChain->SetBranchAddress("Electron_HOverE", &Electron_HOverE, &b_Electron_HOverE);
   fChain->SetBranchAddress("Electron_losthits", &Electron_losthits, &b_Electron_losthits);
   fChain->SetBranchAddress("Electron_passEcaldriven", &Electron_passEcaldriven, &b_Electron_passEcaldriven);
   fChain->SetBranchAddress("Electron_passEMHD1iso", &Electron_passEMHD1iso, &b_Electron_passEMHD1iso);
   fChain->SetBranchAddress("Electron_passN1TrkIso", &Electron_passN1TrkIso, &b_Electron_passN1TrkIso);
   fChain->SetBranchAddress("Electron_Phi", &Electron_Phi, &b_Electron_Phi);
   fChain->SetBranchAddress("Electron_PtHEEP", &Electron_PtHEEP, &b_Electron_PtHEEP);
   fChain->SetBranchAddress("Electron_Px", &Electron_Px, &b_Electron_Px);
   fChain->SetBranchAddress("Electron_Py", &Electron_Py, &b_Electron_Py);
   fChain->SetBranchAddress("Electron_Pz", &Electron_Pz, &b_Electron_Pz);
   fChain->SetBranchAddress("Electron_sce25bye55", &Electron_sce25bye55, &b_Electron_sce25bye55);
   fChain->SetBranchAddress("Electron_scEnergy", &Electron_scEnergy, &b_Electron_scEnergy);
   fChain->SetBranchAddress("Electron_scEta", &Electron_scEta, &b_Electron_scEta);
   fChain->SetBranchAddress("Electron_trackiso", &Electron_trackiso, &b_Electron_trackiso);
   fChain->SetBranchAddress("elstatus", &elstatus, &b_elstatus);
   fChain->SetBranchAddress("gencharge", &gencharge, &b_gencharge);
   fChain->SetBranchAddress("genEnergy", &genEnergy, &b_genEnergy);
   fChain->SetBranchAddress("genEta", &genEta, &b_genEta);
   fChain->SetBranchAddress("GenHT", &GenHT, &b_GenHT);
   fChain->SetBranchAddress("GenJets", &GenJets, &b_GenJets);
   fChain->SetBranchAddress("GenJets_HTMask", &GenJets_HTMask, &b_GenJets_HTMask);
   fChain->SetBranchAddress("GenJets_MHTMask", &GenJets_MHTMask, &b_GenJets_MHTMask);
   fChain->SetBranchAddress("GenMET", &GenMET, &b_GenMET);
   fChain->SetBranchAddress("GenMETPhi", &GenMETPhi, &b_GenMETPhi);
   fChain->SetBranchAddress("genPhi", &genPhi, &b_genPhi);
   fChain->SetBranchAddress("genPt", &genPt, &b_genPt);
   fChain->SetBranchAddress("globalTightHalo2016Filter", &globalTightHalo2016Filter, &b_globalTightHalo2016Filter);
   fChain->SetBranchAddress("HBHEIsoNoiseFilter", &HBHEIsoNoiseFilter, &b_HBHEIsoNoiseFilter);
   fChain->SetBranchAddress("HBHENoiseFilter", &HBHENoiseFilter, &b_HBHENoiseFilter);
   fChain->SetBranchAddress("JetID", &JetID, &b_JetID);
   fChain->SetBranchAddress("JetIDJECdown", &JetIDJECdown, &b_JetIDJECdown);
   fChain->SetBranchAddress("JetIDJECup", &JetIDJECup, &b_JetIDJECup);
   fChain->SetBranchAddress("JetIDJERdown", &JetIDJERdown, &b_JetIDJERdown);
   fChain->SetBranchAddress("JetIDJERup", &JetIDJERup, &b_JetIDJERup);
   fChain->SetBranchAddress("Jets", &Jets, &b_Jets);
   fChain->SetBranchAddress("Jets_ID", &Jets_ID, &b_Jets_ID);
   fChain->SetBranchAddress("JetsJECdown", &JetsJECdown, &b_JetsJECdown);
   fChain->SetBranchAddress("JetsJECdown_ID", &JetsJECdown_ID, &b_JetsJECdown_ID);
   fChain->SetBranchAddress("JetsJECup", &JetsJECup, &b_JetsJECup);
   fChain->SetBranchAddress("JetsJECup_ID", &JetsJECup_ID, &b_JetsJECup_ID);
   fChain->SetBranchAddress("JetsJERdown", &JetsJERdown, &b_JetsJERdown);
   fChain->SetBranchAddress("JetsJERdown_ID", &JetsJERdown_ID, &b_JetsJERdown_ID);
   fChain->SetBranchAddress("JetsJERup", &JetsJERup, &b_JetsJERup);
   fChain->SetBranchAddress("JetsJERup_ID", &JetsJERup_ID, &b_JetsJERup_ID);
   fChain->SetBranchAddress("madHT", &madHT, &b_madHT);
   fChain->SetBranchAddress("MET", &MET, &b_MET);
   fChain->SetBranchAddress("METDown", &METDown, &b_METDown);
   fChain->SetBranchAddress("METPhi", &METPhi, &b_METPhi);
   fChain->SetBranchAddress("METPhiDown", &METPhiDown, &b_METPhiDown);
   fChain->SetBranchAddress("METPhiUp", &METPhiUp, &b_METPhiUp);
   fChain->SetBranchAddress("METUp", &METUp, &b_METUp);
   fChain->SetBranchAddress("motherPDGID", &motherPDGID, &b_motherPDGID);
   fChain->SetBranchAddress("MuonEnergy", &MuonEnergy, &b_MuonEnergy);
   fChain->SetBranchAddress("MuonEta", &MuonEta, &b_MuonEta);
   fChain->SetBranchAddress("MuonIsGlobal", &MuonIsGlobal, &b_MuonIsGlobal);
   fChain->SetBranchAddress("MuonPassID", &MuonPassID, &b_MuonPassID);
   fChain->SetBranchAddress("MuonPhi", &MuonPhi, &b_MuonPhi);
   fChain->SetBranchAddress("MuonPt", &MuonPt, &b_MuonPt);
   fChain->SetBranchAddress("nAllVertices", &nAllVertices, &b_nAllVertices);
   fChain->SetBranchAddress("NumEvents", &NumEvents, &b_NumEvents);
   fChain->SetBranchAddress("NumInteractions", &NumInteractions, &b_NumInteractions);
   fChain->SetBranchAddress("NVtx", &NVtx, &b_NVtx);
   fChain->SetBranchAddress("objectE", &objectE, &b_objectE);
   fChain->SetBranchAddress("objecteta", &objecteta, &b_objecteta);
   fChain->SetBranchAddress("objectphi", &objectphi, &b_objectphi);
   fChain->SetBranchAddress("objectPt", &objectPt, &b_objectPt);
   fChain->SetBranchAddress("PDFids", &PDFids, &b_PDFids);
   fChain->SetBranchAddress("PDFweights", &PDFweights, &b_PDFweights);
   fChain->SetBranchAddress("PDGID", &PDGID, &b_PDGID);
   fChain->SetBranchAddress("PFCaloMETRatio", &PFCaloMETRatio, &b_PFCaloMETRatio);
   fChain->SetBranchAddress("puSysDown", &puSysDown, &b_puSysDown);
   fChain->SetBranchAddress("puSysUp", &puSysUp, &b_puSysUp);
   fChain->SetBranchAddress("puWeight", &puWeight, &b_puWeight);
   fChain->SetBranchAddress("rho", &rho, &b_rho);
   fChain->SetBranchAddress("ScaleWeights", &ScaleWeights, &b_ScaleWeights);
   fChain->SetBranchAddress("TauEta", &TauEta, &b_TauEta);
   fChain->SetBranchAddress("TauPhi", &TauPhi, &b_TauPhi);
   fChain->SetBranchAddress("TauPt", &TauPt, &b_TauPt);
   fChain->SetBranchAddress("TriggerNames", &TriggerNames, &b_TriggerNames);
   fChain->SetBranchAddress("TriggerPass", &TriggerPass, &b_TriggerPass);
   fChain->SetBranchAddress("TriggerPrescales", &TriggerPrescales, &b_TriggerPrescales);
   fChain->SetBranchAddress("TrueNumInteractions", &TrueNumInteractions, &b_TrueNumInteractions);
   fChain->SetBranchAddress("Weight", &Weight, &b_Weight);
   Notify();
}

Bool_t LQcode::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void LQcode::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t LQcode::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef LQcode_cxx
