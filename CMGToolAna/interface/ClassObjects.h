#ifndef CLOBJECTS_H //__CLOBJECTS_H___
#define CLOBJECTS_H

#include "NtupleTools3.h"

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <TLorentzVector.h>
#include <TCanvas.h>
#include <TH1F.h>
#include <TFile.h>

// shouldn't be using 'using namespace' in header files
//using namespace std;

//////////////////////////
// Object classes
//////////////////////////

// common object variable class ~ simple TLorentzVector -> inherit from TLV??
class ParticleObject: public TLorentzVector{

public:
// inherit baseclass constructors (C++11)
    using TLorentzVector::TLorentzVector;
    ParticleObject() {}
// common variables for all obejcts, except TLV
};

// Lepton
class Lepton: public ParticleObject{
public:
    using ParticleObject::ParticleObject;

    int pdgID;
    double relIso03;
    bool tightID;
    int charge;
};


// Generator Lepton
class GenLepton: public ParticleObject{
public:
    using ParticleObject::ParticleObject;

    int status;
};

// Jet
class Jet: public ParticleObject{
private:
// determine btag in constructor?
//    Jet() { if(btagCSV > 0.676) btag = true; }

public:
    bool btag;
    double btagCSV;
};


// MET
/*
class MET: public ParticleObject{
public:

//    double met(){ return TLorentzVector::Pt() }
    double met(){ return Pt(); }
    double HT;
};
*/

// Extend the EasyChain class with getObjects functions
class ObjectChain: public EasyChain {
public:
    using EasyChain::EasyChain;
    ObjectChain(const char* tname) : EasyChain(tname){}

    bool debug_ = false;

    void GetMET(TLorentzVector & MET);
    void GetGenMET(TLorentzVector & genMET);
    void GetMETnoPU(TLorentzVector & METnoPU);

    void GetLeptons(vector<Lepton> * leptons, vector<Lepton> *electrons, vector<Lepton> *muons, vector<Lepton> * vetolep);
    void GetGenLeptons(vector<GenLepton> lepton, vector<GenLepton> electron, vector<GenLepton> muon);
    void GetGenLeptonsFromTau(vector<GenLepton> lepton, vector<GenLepton> electron, vector<GenLepton> muon);
    void GetGenTaus(vector<GenLepton> lepton);

//    void GetJets(vector<Jet> goodJet, vector<Jet> goodBJet);
    void GetJets(vector<Jet>* jets, vector<Jet>* bjets);

// to be written ?
/*
  void GetElectrons(vector<Object> object);
  void GetMuons(vector<Object> object);
  void GetGoodLeptons(vector<Object> object);
  void GetGoodElectrons(vector<Object> object);
  void GetGoodMuons(vector<Object> object);
*/

};


// non class objects
/*
// objects number can be aslo detemined as object.size()

int nLepGood;
int nMuGood;
int nElGood;

int nLepVeto;
int nElVeto;
int nMuVeto;

int nJetGood;
int nBJetGood;

int nGenTau;
int nGenLep;
int nGenLepFromTau;

// global variables

double ST = 0;
double HT = 0;
*/

#endif //__CLOBJECTS_H___


/*
#ifndef CLOBJVAR_H //__CLOBJVAR_H___
#define CLOBJVAR_H

double HT = 0;

#endif CLOBJVAR_H //__CLOBJVAR_H___
*/
