from classes import System, Car, Ownership, User


def test_system_debt():
    system = System()

    start_date = '2020-10-05'
    end_date = '2020-10-25'

    user = User('Victor', 'email', 'abc')
    carA = Car('a', 'b', 2000, 10)
    carB = Car('c', 'd', 2000, 20)

    user_id = system.add_user(user)
    carA_id = system.add_car(carA)
    carB_id = system.add_car(carB)

    system.give_ownership(user_id, carA_id, start_date, end_date)
    system.give_ownership(user_id, carB_id, start_date, end_date)

    first_debt = (20 * 20 * 1.15) + (20 * 10 * 1.15)

    assert system.calculate_user_debt(user_id) == first_debt

    system.remove_ownership(carA_id)

    second_debt = (20 * 20 * 1.15)

    assert system.calculate_user_debt(user_id) == second_debt

    system.remove_ownership(carB_id)

    third_debt = 0

    assert system.calculate_user_debt(user_id) == third_debt


def test_system_ownership_block():
    system = System()

    start_date = '2020-10-05'
    end_date = '2020-10-25'

    user = User('Victor', 'email', 'abc')
    carA = Car('a', 'b', 2000, 10)

    user_id = system.add_user(user)
    carA_id = system.add_car(carA)

    response = system.give_ownership(user_id, carA_id, start_date, end_date)

    assert response == True

    response = system.give_ownership(
        user_id, carA_id, start_date, end_date)

    assert response == False

    first_debt = (20 * 10 * 1.15)

    assert system.calculate_user_debt(user_id) == first_debt

    # repeated removal
    system.remove_ownership(carA_id)
    system.remove_ownership(carA_id)

    second_debt = 0

    assert system.calculate_user_debt(user_id) == second_debt
