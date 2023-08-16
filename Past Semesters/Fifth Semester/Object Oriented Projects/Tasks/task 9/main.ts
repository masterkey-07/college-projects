interface Entidade {
  isPlataforma(): boolean;
  cadastrar(observador: Observador): void;
  remover(observador: Observador): void;
  notificar(): void;
}

interface Observador {
  atualizar(entidade: Entidade): void;
}

class EntidadeInstituto implements Entidade {
  private observadores: Observador[];

  public nome: string;
  constructor(nome: string) {
    this.nome = nome;
    this.observadores = [];
  }

  public isPlataforma(): boolean {
    return false;
  }

  public cadastrar(observador: Observador): void {
    this.observadores.push(observador);
  }

  public remover(observador: Observador): void {
    this.observadores.pop();
  }

  public notificar(): void {
    this.observadores.forEach((observador) => {
      observador.atualizar(this);
    });
  }
}

class EntidadePlataforma implements Entidade {
  private observadores: Observador[];

  public nome: string;
  constructor(nome: string, instituto: ObservadorInstituto) {
    this.nome = nome;
    this.observadores = [instituto];
  }

  public isPlataforma(): boolean {
    return true;
  }

  public cadastrar(observador: Observador): void {
    this.observadores.push(observador);
  }

  public remover(observador: Observador): void {
    this.observadores.pop();
  }

  public notificar(): void {
    this.observadores.forEach((observador) => observador.atualizar(this));
  }
}

class ObservadorInstituto implements Observador {
  private instituto: EntidadeInstituto;
  private atualizado: boolean;

  constructor(instituto: EntidadeInstituto) {
    this.instituto = instituto;
    this.atualizado = false;
  }

  public atualizar(entidade: Entidade): void {
    console.log("sistema do " + this.instituto.nome + " foi atualizado");

    if (entidade.isPlataforma()) this.instituto.notificar();
  }
}

class Cliente {
  public rodar() {
    const institutoA = new EntidadeInstituto("Unifesp");
    const institutoB = new EntidadeInstituto("Fatec");
    const institutoC = new EntidadeInstituto("Unesp");

    const observadorA = new ObservadorInstituto(institutoA);
    const observadorB = new ObservadorInstituto(institutoB);
    const observadorC = new ObservadorInstituto(institutoC);

    const entidadePlatA = new EntidadePlataforma("Alunos", observadorA);
    const entidadePlatB = new EntidadePlataforma("Profs", observadorA);
    const entidadePlatC = new EntidadePlataforma("Cornos", observadorB);
    const entidadePlatD = new EntidadePlataforma("Vagas", observadorC);

    institutoA.cadastrar(observadorB);
    institutoA.cadastrar(observadorC);

    institutoB.cadastrar(observadorA);
    institutoB.cadastrar(observadorC);

    institutoC.cadastrar(observadorA);
    institutoC.cadastrar(observadorB);

    entidadePlatC.notificar();
  }
}

const cliente = new Cliente();

cliente.rodar();
