type FakeImageBuffer = number;

interface IFakeProcessMethod {
  process(image: FakeImageBuffer): FakeImageBuffer;
}

interface IFakeUser {
  getLogin(): [string, string];
}

class FakeUser implements IFakeUser {
  private name: string;
  private password: string;

  constructor(name: string, password: string) {
    this.name = name;
    this.password = password;
  }

  public getLogin(): [string, string] {
    return [this.name, this.password];
  }
}

class FakeUserValidator {
  validate(user: IFakeUser) {
    const [name, password] = user.getLogin();

    return name !== password;
  }
}

interface IFakeProcessMethod {
  process(buffer: FakeImageBuffer): FakeImageBuffer;
}

class FakePhotoshop {
  private buffer: FakeImageBuffer;

  constructor(user: IFakeUser) {
    const result = new FakeUserValidator().validate(user);

    if (!result) throw new Error("Not a Valid User. Must pay License.");
  }

  public selectImage(path: string) {
    this.buffer = Number.MAX_VALUE / path.length;
  }

  public processImage(method: IFakeProcessMethod) {
    return method.process(this.buffer);
  }

  public getFakeImageBuffer(): FakeImageBuffer {
    return structuredClone(this.buffer);
  }
}

class FakeGUIApplication {
  private methods: IFakeProcessMethod[];
  private user: FakeUser;
  private makeLogin(name: string, password: string) {
    this.user = new FakeUser(name, password);
  }

  private photoshop: FakePhotoshop;

  constructor() {
    this.methods = [
      /*Loads Concrete Classes of IFakeProcessMethod*/
    ];

    this.makeLogin("Joe Doe", "123456"); //simulates user input

    try {
      this.photoshop = new FakePhotoshop(this.user);
    } catch (error) {
      console.log(error);
    }
  }

  public openImage(path: string) {
    if (path == null) {
      console.log("Image Not Found");
      return;
    }

    this.photoshop.selectImage(path);
  }

  public applyMethod(methodIndex: number) {
    const method = this.methods[methodIndex];

    if (method == null) {
      console.log("Method Not Found");
      return;
    }

    this.photoshop.processImage(method);
  }

  public displayImage() {
    const buffer = this.photoshop.getFakeImageBuffer();

    if (buffer == null) {
      console.log("No Image was Selected");
      return;
    }

    console.log(String(buffer));
  }
}
