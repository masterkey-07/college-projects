class DuplicateUserError(Exception):
    def __init__(self):
        super().__init__("Duplicate User Error")
