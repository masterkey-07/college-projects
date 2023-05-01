type TipoOcorrencia = "assalto" | "incendio" | "doença";

interface Sujeito {
  getNome(): string;
  assalto(): void;
  doente(): void;
  incendio(): void;
}

interface Observador {
  percebe(entidade: Sujeito, tipo: TipoOcorrencia): void;
}

class SujeitoConcreto implements Sujeito {
  private observadores: Observador[];
  private nome: string;

  constructor(nome: string, observadores: Observador[]) {
    this.nome = nome;
    this.observadores = observadores;
  }

  public getNome(): string {
    return this.nome;
  }

  public assalto() {
    this.observadores.forEach((observador) =>
      observador.percebe(this, "assalto")
    );
  }
  public doente() {
    this.observadores.forEach((obs) => obs.percebe(this, "doença"));
  }
  public incendio() {
    this.observadores.forEach((obs) => obs.percebe(this, "incendio"));
  }
}

class PessoaObservadora implements Observador {
  private governo: Governo;
  private sujeito: Sujeito;

  constructor(sujeito: Sujeito, governo: Governo) {
    this.sujeito = sujeito;
    this.governo = governo;
  }

  public percebe(entidade: Sujeito, tipo: TipoOcorrencia): void {
    this.governo.receberOcorrencia(entidade, tipo);
  }
}

class Governo {
  private bombeiro: Bombeiro;
  private policia: Policia;
  private hospital: Hospital;

  private static instancia: Governo;

  private constructor() {
    this.bombeiro = new Bombeiro(this);
    this.policia = new Policia(this);
    this.hospital = new Hospital(this);
  }

  public static pegarContato(): Governo {
    if (this.instancia === null) this.instancia = new Governo();

    return this.instancia;
  }

  public receberOcorrencia(sujeito: Sujeito, tipo: TipoOcorrencia) {
    if (tipo === "assalto") this.policia.envia(sujeito);
    else if (tipo === "doença") this.hospital.envia(sujeito);
    else if (tipo === "incendio") this.bombeiro.envia(sujeito);
  }
}

interface OrgaoPublico {
  envia(sujeito: Sujeito): void;
}

class Policia implements OrgaoPublico {
  private governo: Governo;

  constructor(governo: Governo) {
    this.governo = governo;
  }

  public envia(sujeito: Sujeito): void {
    console.log(`Policia enviada para ${sujeito.getNome()}`);
  }
}
class Hospital implements OrgaoPublico {
  private governo: Governo;

  constructor(governo: Governo) {
    this.governo = governo;
  }

  public envia(sujeito: Sujeito): void {
    console.log(`Ambulancia enviada para ${sujeito.getNome()}`);
  }
}

class Bombeiro implements OrgaoPublico {
  private governo: Governo;

  constructor(governo: Governo) {
    this.governo = governo;
  }

  public envia(sujeito: Sujeito): void {
    console.log(`Bombeiro enviado para ${sujeito.getNome()}`);
  }
}
