#ifndef OUR_HOUSE_H
#define OUR_HOUSE_H


namespace solid {

// ******************
// *** INTERFACES ***
// ******************

// --------------------------
// --- button_client_if.h ---
// --------------------------
class button_client_if
{
public:
    virtual void turn_on() = 0;
    virtual void turn_off() = 0;
};

// --------------------------
// --- dimable_client_if.h ---
// --------------------------
class dimmer_client_if
{
public:
    virtual void do_dimm(float level) = 0;
};


// -------------------
// --- button_if.h ---
// -------------------
class button_if
{
public:
    explicit button_if(button_client_if& bc);
    void detect();
    virtual bool get_state() const = 0;
private:
    button_client_if& button_client_;
};

// -----------------------------------
// --- dimmer_value_validator_if.h ---
// -----------------------------------
class dimmer_value_validator_if
{
public:
    virtual bool is_valid(float level) const = 0;
};

// -------------------
// --- dimmer_if.h ---
// -------------------
class dimmer_if
{
public:
    explicit dimmer_if(dimmer_client_if& dc, dimmer_value_validator_if& validator);
    void detect();
    virtual float get_dimm_level() const = 0;
private:
    dimmer_client_if& dimmer_client_;
    dimmer_value_validator_if& validator_;
};



// ************************
// *** CONCRETE CLASSES ***
// ************************
// --------------------------------
// --- dimmer_value_validator.h ---
// --------------------------------
class dimmer_value_validator: public dimmer_value_validator_if
{
public:
    bool is_valid(float level) const override;
};

// --------------
// --- lamp.h ---
// --------------
class lamp : public button_client_if, public dimmer_client_if
{
public:
    void turn_on() override;
    void turn_off() override;
    void do_dimm(float level) override;
};

// ----------------------
// --- kitchen_vent.h ---
// ----------------------
// what to do if this vent also has a light that we wish to turn on and off independetly
// from the fan on/off ... which is common functionality in a kitchen ventilator ?
class kitchen_vent : public button_client_if //, public ventilator_if ?
{
public:
    void turn_on() override;
    void turn_off() override;
};

// ----------------
// --- button.h ---
// ----------------
class button: public button_if
{
public:
    button(button_client_if& bc);
    void set_state (bool state);
    bool get_state() const override;
private:
    bool state_ = false;
};


// ----------------
// --- dimmer.h ---
// ----------------
class dimmer: public dimmer_if
{
public:
    dimmer(dimmer_client_if& bc, dimmer_value_validator_if& validator);
    void set_level (float level);
    float get_dimm_level() const override;
private:
    float level_ = 0;
};


// -------------------
// --- our_house.h ---
// -------------------

// our_house only holds references to it's components.
// So how would we copy our_house and make a neighbor, withou us controlling his lights?
// So our_house can't simply be copied. We have lost the benefits of value sematics, which may or may
// not what we really want.
//
class our_house
{
public:
    our_house(button_client_if& kitchen_lamp,
              button_if& kitchen_light_switch,
              dimmer_if& kitchen_light_dimmer,
              button_client_if& kitchen_ventilator,
              button_if& kitchen_vent_switch);
    void enter_kitchen (bool kitchen_lamp_state);
private:
    button_client_if&   kitchen_lamp_;
    button_if&          kitchen_light_switch_;
    dimmer_if&          kitchen_light_dimmer_;
    button_client_if&   kitchen_vent_;
    button_if&          kitchen_vent_switch_;
};

// -------------------
// --- our_house.h ---
// -------------------


} // end namespace solid

int our_house_example(int argc, char** argv);



#endif // OUR_HOUSE_H
