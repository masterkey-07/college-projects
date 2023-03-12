from enums import Priority


class TodoItem:
    def __init__(self, description, priority=Priority.LOW):
        self.description = description
        self.priority = priority
        self.done = False

    def complete(self):
        self.done = True

    def undo(self):
        self.done = False

    def is_done(self) -> bool:
        return self.done

    def change_description(self, description):
        self.description = description
