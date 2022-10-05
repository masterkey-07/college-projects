from abc import ABC, abstractmethod


class Switchable (ABC):
    @abstractmethod
    def turn_on(self):
        pass

    def turn_off(self):
        pass


class LightBulb(Switchable):
    def turn_on(self):
        print("Lightbulb: turned on")

    def turn_off(self):
        print("Lightbulb: turned off")


class Fan(Switchable):
    def turn_on(self):
        print("Fan: turned on")

    def turn_off(self):
        print("Fan: turned off")


class PowerSwitch:
    def __init__(self, switchable: Switchable):
        self.switchable = switchable

        self.on = False

    def press(self):
        if self.on:
            self.switchable.turn_off()
            self.on = False
        else:
            self.switchable.turn_on()
            self.on = True


powerSwitchA = PowerSwitch(Fan())
powerSwitchB = PowerSwitch(LightBulb())

powerSwitchA.press()
powerSwitchB.press()
powerSwitchA.press()
powerSwitchB.press()
