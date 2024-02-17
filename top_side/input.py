import inputs
import threading

#index is the controller value [First controller: 0, Second Controller: 1, etc.]
class controller:
    def __init__(self, index):
        self.right_stick = (0, 0)
        self.left_stick = (0, 0)
        self.y_pressed = 0
        self.x_pressed = 0
        self.b_pressed = 0
        self.btn_tl = 0
        self.btn_tr = 0
        self.device = inputs.devices.gamepads[index]
        self._thread()

    def _run(self):
        while True:
            for event in self.device.read():
                match str(event.code):
                    case "ABS_X":
                        self.left_stick = (event.state / 32768, self.left_stick[1])
                        break
                    case "ABS_Y":
                        self.left_stick = (self.left_stick[0], event.state / 32768)
                        break
                    case "ABS_RX":
                        self.right_stick = (event.state / 32768, self.right_stick[1])
                        break
                    case "ABS_RY":
                        self.right_stick = (self.right_stick[0], event.state / 32768)
                        break
                    case "BTN_NORTH":
                        self.y_pressed = ('1' if event.state == 1 else '0')
                        break
                    case "BTN_EAST":
                        self.b_pressed = ('1' if event.state == 1 else '0')
                    case "BTN_WEST":
                        self.x_pressed = ('1' if event.state == 1 else '0')
                    case "BTN_TL":
                        self.btn_tl = ('1' if event.state == 1 else '0')
                    case "BTN_TR":
                        self.btn_tr = ('1' if event.state == 1 else '0')
                    case "SYN_REPORT": break # don't care YET
                    case _:
                        print(str(event.code) + ": " + str(event.state))
    
    def _thread(self):
        _run_thread = threading.Thread(target=self._run, daemon=True)
        _run_thread.start()