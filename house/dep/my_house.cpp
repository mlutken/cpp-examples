
#include "my_house.h"


#include <iostream>

using namespace std;
namespace dep {



// ************************
// *** CONCRETE CLASSES ***
// ************************

//// ----------------------------------
//// --- dimmer_value_validator.cpp ---
//// ----------------------------------
//bool dimmer_value_validator::is_valid(float level) const
//{
//    return 0.0f <= level && level <= 1.0f;
//}

//// ----------------
//// --- lamp.cpp ---
//// ----------------
//void lamp::turn_on()
//{
//}

//void lamp::turn_off()
//{
//}

//void lamp::do_dimm(float /*level*/)
//{

//}


//// ------------------------
//// --- kitchen_vent.cpp ---
//// ------------------------
//void kitchen_vent::turn_on()
//{
//}

//void kitchen_vent::turn_off()
//{
//}


//// ------------------
//// --- button.cpp ---
//// ------------------
//button::button(button_client_if& bc)
//    : button_if(bc)
//{}


//void button::set_state (bool state)
//{
//    state_ = state;
//}

//bool button::get_state() const
//{
//    return state_;
//}


//// ------------------
//// --- dimmer.cpp ---
//// ------------------
//dimmer::dimmer(dimmer_client_if& bc, dimmer_value_validator_if& validator)
//    : dimmer_if(bc, validator)
//{}

//void dimmer::set_level(float level)
//{
//    level_ = level;
//}


//float dimmer::get_dimlevel() const
//{
//    return level_;
//}


//// ---------------------
//// --- our_house.cpp ---
//// ---------------------


//our_house::our_house(button_client_if& kitchen_lamp,
//                     button_if& kitchen_light_switch,
//                     dimmer_if& kitchen_light_dimmer,
//                     button_client_if& kitchen_ventilator,
//                     button_if& kitchen_vent_switch)
//    : kitchen_lamp_(kitchen_lamp),
//      kitchen_light_switch_(kitchen_light_switch),
//      kitchen_light_dimmer_(kitchen_light_dimmer),
//      kitchen_vent_(kitchen_ventilator),
//      kitchen_vent_switch_(kitchen_vent_switch)

//{
//}

//void our_house::enter_kitchen(bool /*kitchen_lamp_state*/)
//{

//}





} // END namespace solid

int my_house_example(int , char** )
{
    using namespace dep;
    cerr << "--- My house example (DEP) ---\n";


    // Create my_house
//    lamp kitchen_lamp;
//    button kitchen_light_switch(kitchen_lamp); // Here we sacrificed the default constructor
//    dimmer_value_validator dim_validator;
//    dimmer kitchen_light_dimmer(kitchen_lamp, dim_validator);

//    kitchen_vent kitchen_ventilator;
//    button kitchen_vent_switch(kitchen_ventilator);

//    our_house house(kitchen_lamp,
//                    kitchen_light_switch,
//                    kitchen_light_dimmer,
//                    kitchen_ventilator,
//                    kitchen_vent_switch);

//    house.enter_kitchen(true);

    return 0;
}


