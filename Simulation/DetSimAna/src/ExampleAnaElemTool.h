#ifndef ExampleAnaElemTool_h
#define ExampleAnaElemTool_h

#include "GaudiKernel/AlgTool.h"
#include "FWCore/DataHandle.h"
#include "DetSimInterface/IAnaElemTool.h"

#include "plcio/SimTrackerHitCollection.h"

class ExampleAnaElemTool: public extends<AlgTool, IAnaElemTool> {

public:

    using extends::extends;

    /// IAnaElemTool interface
    // Run
    virtual void BeginOfRunAction(const G4Run*) override;
    virtual void EndOfRunAction(const G4Run*) override;

    // Event
    virtual void BeginOfEventAction(const G4Event*) override;
    virtual void EndOfEventAction(const G4Event*) override;

    // Tracking
    virtual void PreUserTrackingAction(const G4Track*) override;
    virtual void PostUserTrackingAction(const G4Track*) override;

    // Stepping
    virtual void UserSteppingAction(const G4Step*) override;


    /// Overriding initialize and finalize
    StatusCode initialize() override;
    StatusCode finalize() override;

private:
    DataHandle<plcio::SimTrackerHitCollection> m_trackerCol{"SimTrackerCol", 
            Gaudi::DataHandle::Writer, this};

};

#endif
