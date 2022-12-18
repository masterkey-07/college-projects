import pytest

from src.app import create_app
from src.usecases.errors.duplicateusererror import DuplicateUserError


def create_user_payload():
    return {
        "name": 'Joe Doe',
        "email": 'joe@doe.com',
        "password": 'test1234TEST&'
    }


@pytest.fixture
def client():
    app = create_app()
    app.config['TESTING'] = True

    with app.app_context():
        with app.test_client() as client:
            yield client


def test_user_signup(client):
    payload = create_user_payload()

    response = client.post("/api/users", json=payload)

    assert response.status_code == 201
    assert response.json['name'] is not None
    assert response.json['email'] is not None


def test_duplicate_user(client):
    payload = create_user_payload()

    response = client.post("/api/users", json=payload)

    response = client.post("/api/users", json=payload)

    assert response.status_code == 400

    assert response.json['error'] == str(DuplicateUserError())
