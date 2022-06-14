#ifndef MY_HOUSE_H
#define MY_HOUSE_H

#include <functional>

// References:
// 1) http://qualityisspeed.blogspot.com/2014/08/why-i-dont-teach-solid.html
// 2) http://qualityisspeed.blogspot.com/2014/09/beyond-solid-dependency-elimination.html
// 3) http://qualityisspeed.blogspot.com/2015/04/dependency-elimination-example-primitive-support.html
// 4) http://qualityisspeed.blogspot.com/2015/02/the-dependency-elimination-principle-a-canonical-example.html
// 5) https://lostechies.com/derekgreer/2008/12/28/examining-dependency-inversion/
// 6)
// 7)
// 8)
// 9)


namespace dep {


// ************************
// *** CONCRETE CLASSES ***
// ************************

enum class active_state { on, off };
using active_slot = std::function<void (active_state)>;
//using active_signal = std::function<active_state ()>;

// --------------------
// --- dimm_level.h ---
// --------------------
// Making dimmer levels "first class citizens" that can be passed around and validated.
// Furthermore this simple class can be unit tested without any mocks in a simple strai
// forward way involving "normal style" code and simple EXPECT_EQUAL as opposed to using
// EXPECT_CALL.
class dimm_level
{
public:
    using slot = std::function<void (dimm_level)>;

    dimm_level() = default;
    explicit        dimm_level  (float val) : value_(val) {}

    float           value       () const        { return value_;  }
    void            set_value   (float val)     { value_ = val;   }
    bool            is_valid    () const;
private:
    float value_ = 0;
};



// ----------------
// --- button.h ---
// ----------------
class button
{
public:
    //button() = default;   // Now we can default copnstruct. This is a good thing!
    void            connect     (const active_slot& slot)   { slot_ = slot;     }
    active_state    state       () const                    { return state_;    }
    void            set_state   (active_state state)        { state_ = state;   }
    void            detect      ();
private:
    active_slot     slot_;
    active_state    state_ = active_state::off;
};

// --------------
// --- lamp.h ---
// --------------
class lamp
{
public:
    active_state        lights_state        () const                { return lights_state_; }
    const dimm_level&   lights_dimm_level   () const                { return lights_dimm_level_;   }
    void                lights_on_off       (active_state state);
    void                do_dimm             (const dimm_level& level);

private:
    active_state    lights_state_       = active_state::off;
    dimm_level      lights_dimm_level_;
};

// ----------------------
// --- kitchen_vent.h ---
// ----------------------
class kitchen_vent //, public ventilator_if : No problem here since  we really ARE a ventialtor! In case we need to treat a number of DIFFERENT ventialator implementation instances polymorphically.
{
public:
    active_state    vent_state  () const                { return vent_state_; }
    void            vent_on_off (active_state state);
    //void lights_on_off (active_state state); // Now we can easily add a lamp inside the ventialtor if we need .....

private:
    active_state vent_state_ = active_state::off;
};



// ----------------
// --- dimmer.h ---
// ----------------
class dimmer
{
public:
//    dimmer();
    void                connect     (const dimm_level::slot& slot)  { slot_ = slot;     }
    const dimm_level&   level       () const                        { return level_;    }
    void                set_level   (dimm_level level);
    void                detect      ();

private:
    dimm_level::slot    slot_;
    dimm_level          level_;
};


// ------------------
// --- my_house.h ---
// ------------------

//
class my_house
{
public:
    my_house();
    void enter_kitchen (active_state kitchen_lamp_state);
private:
    // NOTE: Now all members a VALUES and not just REFERENCES. C++ is very much about values.
    //       Values are simpler to contruct, they can be passed, copied (or moved) around and they never leak memory.
    //       Just take a look at the standard library. Except for iostreams. No inheritance in sight!
    //       This is NOT to say inheritance or "dependency inversion" is wrong -- it's just good practice
    //       that if you have a base class with virtual functions you really should strive to have multiple
    //       implementations of this interface/base and use thse polymorphically.


    lamp            kitchen_lamp_;          // Now the lamp really is a lamp and not a "button_client_if"
    button          kitchen_light_switch_;  // Same for the rest...
    dimmer          kitchen_light_dimmer_;
    kitchen_vent    kitchen_vent_;
    button          kitchen_vent_switch_;
};

// -------------------
// --- my_house.h ---
// -------------------


} // end namespace dep

int my_house_example(int argc, char** argv);



#endif // my_house_H
