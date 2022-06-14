
#include "my_house.h"
#include "my_house.h"


#include <iostream>

using namespace std;
namespace dep {




// ************************
// *** CONCRETE CLASSES ***
// ************************
// ----------------------
// --- dimm_level.cpp ---
// ----------------------

bool dimm_level::is_valid() const
{
    return 0.0f <= value_ && value_ <= 1.0f;
}

// ------------------
// --- button.cpp ---
// ------------------

void button::detect()
{
    if (slot_) {
        slot_(state());
    }
}

// ----------------
// --- lamp.cpp ---
// ----------------

void lamp::lights_on_off(active_state state)
{
    ligths_state_ = state;
    // Do whatever is needed to actually turn on the lamp....
}


// ------------------------
// --- kitchen_vent.cpp ---
// ------------------------

void kitchen_vent::vent_on_off(active_state state)
{
    vent_state_ = state;
    // Do whatever is needed to actually turn on the ventilator ....
}



// ------------------
// --- dimmer.cpp ---
// ------------------

void dimmer::set_level(dimm_level level)
{
    if (level.is_valid()) {
        level_ = level;
    }
}

void dimmer::detect()
{
    if (slot_ && level().is_valid()) {
        slot_(level());
    }
}


// ---------------------
// --- my_house.cpp ---
// ---------------------

my_house::my_house()
{
    // Wire up my house
    kitchen_light_switch_.connect( [this](active_state state) -> void { kitchen_lamp_.lights_on_off (state);} );
    kitchen_vent_switch_. connect( [this](active_state state) -> void { kitchen_vent_.vent_on_off   (state);} );
}

void my_house::enter_kitchen(active_state /*kitchen_lamp_state*/)
{

}




} // END namespace solid

int my_house_example(int , char** )
{
    using namespace dep;
    cerr << "--- My house example (DEP) ---\n";


    // Create my_house
    // Much simpler as my house already CONTAINS all it contents as firt class VALUE members
    // We can even make copies of our_hous without risking that we control the lights in our new
    // neighbors house! They will most likely appreciate that :)

    my_house house;
    house.enter_kitchen(active_state::on);

    my_house neighbor = house;  // Copy my house

    return 0;
}


