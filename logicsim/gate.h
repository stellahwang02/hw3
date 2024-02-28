#ifndef GATE_H
#define GATE_H
#include <vector>
#include <queue>
#include <tuple>
#include "event.h"
#include "wire.h"

class Gate 
{
    public:
        Gate(int, Wire*);
        virtual ~Gate();
        virtual Event* update(uint64_t) =0;
        void wireInput(unsigned int,Wire*);
        
    protected:
      Wire* m_output;
      std::vector<Wire*> m_inputs;
			uint32_t m_delay;
			char m_current_state;
};

class And2Gate : public Gate
{
  public:
      And2Gate(Wire*, Wire*, Wire*);
      Event* update(uint64_t);  
};

class Or2Gate : public Gate
{
  public:
      Or2Gate(Wire*, Wire*, Wire*);
      Event* update(uint64_t);
};

class NotGate : public Gate
{
  public:
      NotGate(Wire*, Wire*, Wire*);
      Event* update(uint64_t);
};


// NotGate::NotGate(Wire* inputWire1, Wire* inputWire2, Wire* outputWire) : Gate(/* parameters for Gate class */), m_output(outputWire) {
    // Initialize the NotGate with the input and output wires
    // wireInput(0, inputWire1);
    // wireInput(1, inputWire2);
    // setOutputWire(m_output);
// }

#endif