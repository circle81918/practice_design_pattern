#include <memory>
#include <iostream>

enum class state_event {
  connect,
  disconnect
};

std::ostream &operator<<(std::ostream &os, const state_event &evt) {
  switch (evt) {
    case state_event::connect: os << "connect"; break;
    case state_event::disconnect: os << "disconnect"; break;
  }
  return os;
}

class State {
  public:
    virtual std::unique_ptr<State> GetNextState(state_event evt) = 0;
};

class ConnectState : public State {
  public:
    std::unique_ptr<State> GetNextState(state_event evt);
};


class IdleState : public State {
  public:
    std::unique_ptr<State> GetNextState(state_event evt);
};

std::unique_ptr<State> ConnectState::GetNextState(state_event evt) {
  std::cout << "connect -> " << evt << std::endl;
  if (evt == state_event::disconnect)  return std::make_unique<IdleState>();
  return nullptr;
}

std::unique_ptr<State> IdleState::GetNextState(state_event evt) {
  std::cout << "idle -> " << evt << std::endl;
  if (evt == state_event::connect) return std::make_unique<ConnectState>();
  return nullptr;
}

class PortableDevice {
  public:
    PortableDevice() {
      cur_state = std::make_unique<IdleState>();
    }
    
    template <typename... events>
    void establish_connection(events... evt) { (StateChange(evt), ...); }

    void StateChange(state_event evt) {
      auto next_state = cur_state->GetNextState(evt);
      if (next_state)
        cur_state = std::move(next_state);
    }

  private:
    std::unique_ptr<State> cur_state;
};

int main() {
  PortableDevice usb;
  usb.establish_connection(state_event::connect, state_event::disconnect);
  return 0;
}



