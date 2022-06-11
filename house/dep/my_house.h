#ifndef MY_HOUSE_H
#define MY_HOUSE_H

#include <functional>

namespace dep {


// ************************
// *** CONCRETE CLASSES ***
// ************************
// --------------------------------
//// --- dimmer_value_validator.h ---
//// --------------------------------
//class dimmer_value_validator: public dimmer_value_validator_if
//{
//public:
//    bool is_valid(float level) const override;
//};

// --------------
// --- lamp.h ---
// --------------
class lamp
{
public:
private:
};

// ----------------------
// --- kitchen_vent.h ---
// ----------------------
// what to do if this vent also has a light that we wish to turn on and off independetly
// from the fan on/off ... which is common functionality in a kitchen ventilator ?
class kitchen_vent //, public ventilator_if : No problem here since  we really ARE a ventialtor!
{
public:
private:
};

// ----------------
// --- button.h ---
// ----------------
class button
{
//public:
//    button(button_client_if& bc);
//    void set_state (bool state);
//    bool get_state() const override;
//private:
//    bool state_ = false;
};


// ----------------
// --- dimmer.h ---
// ----------------
class dimmer
{
//public:
//    dimmer(dimmer_client_if& bc, dimmer_value_validator_if& validator);
//    void set_level (float level);
//    float get_dimlevel() const override;
//private:
//    float level_ = 0;
};


// ------------------
// --- my_house.h ---
// ------------------

//
class my_house
{
public:
//    void enter_kitchen (bool kitchen_lamp_state);
private:
//    button_client_if&   kitchen_lamp_;
//    button_if&          kitchen_light_switch_;
//    dimmer_if&          kitchen_light_dimmer_;
//    button_client_if&   kitchen_vent_;
//    button_if&          kitchen_vent_switch_;
};

// -------------------
// --- our_house.h ---
// -------------------


} // end namespace dep

int my_house_example(int argc, char** argv);



#endif // OUR_HOUSE_H
