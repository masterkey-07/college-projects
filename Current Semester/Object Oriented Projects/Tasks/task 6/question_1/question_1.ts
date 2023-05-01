//Victor Jorge - 156740
//Leonardo Fonseca - 133680

class DVDplayer {
  private DVD: number;

  constructor(DVD: number) {
    this.DVD = DVD;
  }

  public liga() {
    console.log("dvd ligado");
  }

  public inicia() {
    console.log("dvd iniciado");
  }

  public pausa() {
    console.log("dvd pausado");
  }

  public desliga() {
    console.log("dvd desligado");
  }
}

class TVScreen {
  private tela: number;

  constructor(tela: number) {
    this.tela = tela;
  }

  public liga() {
    console.log("tv ligada");
  }

  public desliga() {
    console.log("tv desligada");
  }
}

class SoundSystem {
  private som: number;

  constructor(som: number) {
    this.som = som;
  }

  public toca() {
    console.log("som tocando");
  }

  public muta() {
    console.log("som pausando");
  }
}

class LightSystem {
  private luz: number;

  constructor(luz: number) {
    this.luz = luz;
  }

  public acende() {
    console.log("luz acendida");
  }

  public apaga() {
    console.log("luz apagada");
  }
}

class FoodSystem {
  private luz: number;

  constructor(luz: number) {
    this.luz = luz;
  }

  public produzir() {
    console.log("comida produzida");
  }
}

export class HomeTheaterFacade {
  private static controller: HomeTheaterFacade;

  private player: DVDplayer = new DVDplayer(1);
  private tela: TVScreen = new TVScreen(2);
  private som: SoundSystem = new SoundSystem(3);
  private ifood: FoodSystem = new FoodSystem(4);
  private luminaria: LightSystem = new LightSystem(5);

  private construtor() {}

  public static getControler(): HomeTheaterFacade {
    if (this.controller == null) this.controller = new HomeTheaterFacade();

    return this.controller;
  }

  public iniciaSessao() {
    this.player.liga();
    this.tela.liga();
    this.player.inicia();
    this.som.toca();
    this.luminaria.apaga();
    this.ifood.produzir();
  }

  public pausa() {
    this.player.pausa();
    this.som.muta();
    this.luminaria.acende();
  }

  public despausa() {
    this.player.inicia();
    this.som.toca();
    this.luminaria.apaga();
  }

  public muta() {
    this.som.muta();
  }

  public desmuta() {
    this.som.toca();
  }

  public desliga() {
    this.player.pausa();
    this.som.muta();
    this.luminaria.apaga();
    this.player.desliga();
    this.tela.desliga();
  }
}
