#include <iostream>
#include <memory>

enum State_type {
        off,
        on,
        num_state,
};

class State {

        public:
                virtual void handle() = 0;
};

class State_on: public State {

        public:
                State_on() {
                        std::cout << "  state State_on construct \n";
                };
                void handle() override {
                        std::cout << "  state from State_off to State_on \n";
                };
};

class State_off: public State {

        public:
                State_off() {
                        std::cout << "  state State_off construct \n";
                };
                void handle() override {
                        std::cout << "  state from State_on to State_off \n";
                };
};

class Machine {

        private:
                std::unique_ptr<State> state[State_type::num_state]; 
                int state_index;

        public:
                Machine() {
                        state_index = State_type::off;
                        state[State_type::off] = std::unique_ptr<State>(new State_off());
                        state[State_type::on] = std::unique_ptr<State>(new State_on());
                };

                void operator()() {
                        state[state_index]->handle();
                        state_index = (++state_index == State_type::num_state) ? State_type::off : state_index;
                }
};


int main() {

        Machine fsm;
        
        // show each state in turns
        for (int i = 0; i < 4; i++) {
                std::cout << " Go next ,";
                fsm();
        }
}
