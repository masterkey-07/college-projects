from flask import Flask, request, jsonify
from src.externals.bcrypthashservice import BcryptHashService
from src.usecases.signup import SignUp
from test.usecases.inmemoryuserrepository import InMemoryUserRepository
from bcrypt import gensalt


def create_app():
    app = Flask(__name__)

    hash_service = BcryptHashService(gensalt())
    user_repository = InMemoryUserRepository()

    @app.route("/api/users", methods=['POST'])
    def signup():
        name = request.json['name']
        email = request.json['email']
        password = request.json['password']

        signup = SignUp(user_repository, hash_service)

        try:
            signup.perform(name, email, password)
        except Exception as error:
            return jsonify({"error": str(error)}), 400

        return jsonify({
            "name": name,
            "email": email,
        }), 201

    @app.route('/', methods=['GET'])
    def hello():
        return "<p>Hello World</p>"

    return app
