#ifndef XLAYOUTDISPLAYS_DISPL_H
#define XLAYOUTDISPLAYS_DISPL_H

#include "Mode.h"
#include "Pos.h"

#include <memory>
#include <list>

// a single Xrandr display
class Displ {
public:
    enum State {
        active, connected, disconnected
    };

    Displ(const std::string &name, const State &state, const std::list<ModeP> &modes, const ModeP &currentMode,
          const ModeP &preferredMode, const ModeP &optimalMode, const PosP &currentPos);

    virtual ~Displ() {
    }

    const std::string name;
    const State state;

    const std::list<ModeP> modes;   // should be ordered descending when constructing
    const ModeP currentMode;
    const ModeP preferredMode;
    const ModeP optimalMode;
    ModeP desiredMode;

    const PosP currentPos;
    PosP desiredPos;

    bool desiredActive = false;

    static std::shared_ptr<Displ> desiredPrimary;
};

typedef std::shared_ptr<Displ> DisplP;

#endif //XLAYOUTDISPLAYS_DISPL_H
