import bcrypt
from flask import Flask, request, jsonify
from src.externals.bcrypthashservice import BcryptHashService
from test.usecases.inmemoryuserrepository import InMemoryUserRepository
from src.usecases.signup import SignUp
from src.usecases.signin import SignIn


def create_app():
    app = Flask(__name__)
    salt = bcrypt.gensalt()
    user_repo = InMemoryUserRepository()
    hash_service = BcryptHashService(salt)

    @app.route("/api/users", methods=['POST'])
    def signup():
        name = request.json["name"]
        email = request.json["email"]
        password = request.json["password"]
        signup_usecase = SignUp(user_repo, hash_service)
        try:
            signup_usecase.perform(name, email, password)
        except Exception as error:
            return jsonify({
                "error": str(error)
            }), 400
        result = {
            "name": name,
            "email": email
        }
        return jsonify(result), 201

    @app.route("/api/users/signin", methods=['POST'])
    def signin():
        email = request.json["email"]
        password = request.json["password"]
        signin_usecase = SignIn(user_repo, hash_service)

        try:
            signin_usecase.perform(email, password)
        except Exception as error:
            return jsonify({
                "error": str(error)
            }), 401

        return {}, 200

    return app
