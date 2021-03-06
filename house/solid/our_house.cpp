
#include "our_house.h"


#include <iostream>

using namespace std;
namespace solid {



// ---------------------
// --- button_if.cpp ---
// ---------------------
button_if::button_if(button_client_if& bc)
    : button_client_(bc)
{}

void button_if::detect()
{
    const bool button_on = get_state();
    if (button_on) {
        button_client_.turn_on();
    }
    else {
        button_client_.turn_off();
    }
}

// ---------------------
// --- dimmer_if.cpp ---
// ---------------------
dimmer_if::dimmer_if(dimmer_client_if& dc, dimmer_value_validator_if& validator)
    : dimmer_client_(dc),
      validator_(validator)
{}

void dimmer_if::detect()
{
    const float level = get_dimm_level();
    if (validator_.is_valid(level)) {
        dimmer_client_.do_dimm(level);
    }
}

// ************************
// *** CONCRETE CLASSES ***
// ************************

// ----------------------------------
// --- dimmer_value_validator.cpp ---
// ----------------------------------
bool dimmer_value_validator::is_valid(float level) const
{
    return 0.0f <= level && level <= 1.0f;
}

// ----------------
// --- lamp.cpp ---
// ----------------
void lamp::turn_on()
{
    // Do whatever is needed to actually turn on the lamp....
}

void lamp::turn_off()
{
    // Do whatever is needed to actually turn off the lamp....
}

void lamp::do_dimm(float /*level*/)
{
    // Do whatever is needed to actually dimm the lamp....
}


// ------------------------
// --- kitchen_vent.cpp ---
// ------------------------
void kitchen_vent::turn_on()
{
    // Do whatever is needed to actually turn on the ventilator ....
}

void kitchen_vent::turn_off()
{
    // Do whatever is needed to actually turn off the ventilator ....
}


// ------------------
// --- button.cpp ---
// ------------------
button::button(button_client_if& bc)
    : button_if(bc)
{}



// ------------------
// --- dimmer.cpp ---
// ------------------
dimmer::dimmer(dimmer_client_if& bc, dimmer_value_validator_if& validator)
    : dimmer_if(bc, validator)
{}

void dimmer::set_level(float level)
{
    level_ = level;
}


float dimmer::get_dimm_level() const
{
    return level_;
}


// ---------------------
// --- our_house.cpp ---
// ---------------------


our_house::our_house(button_client_if& kitchen_lamp,
                     button_if& kitchen_light_switch,
                     dimmer_if& kitchen_light_dimmer,
                     button_client_if& kitchen_ventilator,
                     button_if& kitchen_vent_switch)
    : kitchen_lamp_(kitchen_lamp),
      kitchen_light_switch_(kitchen_light_switch),
      kitchen_light_dimmer_(kitchen_light_dimmer),
      kitchen_vent_(kitchen_ventilator),
      kitchen_vent_switch_(kitchen_vent_switch)

{
}

void our_house::enter_kitchen(bool /*kitchen_lamp_state*/)
{

}





} // END namespace solid

int our_house_example(int , char** )
{
    using namespace solid;
    cerr << "--- Our house example (SOLID) ---\n";

    // Now who is responsible for the lifetime of lamps, ventilators and switches in our hous?
    // How do we determine which concrtete instances of the abstract interfaces to actually put into our house?

    // Create our house
    lamp kitchen_lamp;
    button kitchen_light_switch(kitchen_lamp); // Here we sacrificed the default constructor
    dimmer_value_validator dim_validator;
    dimmer kitchen_light_dimmer(kitchen_lamp, dim_validator);

    kitchen_vent kitchen_ventilator;
    button kitchen_vent_switch(kitchen_ventilator);

    our_house house(kitchen_lamp,
                    kitchen_light_switch,
                    kitchen_light_dimmer,
                    kitchen_ventilator,
                    kitchen_vent_switch);

    house.enter_kitchen(true);

    return 0;
}


