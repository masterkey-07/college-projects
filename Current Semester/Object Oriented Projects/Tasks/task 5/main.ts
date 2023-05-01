// Aluno : Victor Jorge; RA : 156740
// Aluno : Leonardo Fonseca; RA : 133680

class Aluno {
  private matricula: number;
  private nome: string;

  constructor(matricula: number, nome: string) {
    this.matricula = matricula;
    this.nome = nome;
  }

  public getMatricula(): number {
    return this.matricula;
  }

  public getNome(): string {
    return this.nome;
  }
}

class Turma {
  private curso: Curso;
  private alunos: Aluno[];

  constructor() {
    this.alunos = [];
  }

  public setCurso(curso: Curso): void {
    this.curso = curso;
  }

  public getCurso(): Curso {
    return this.curso;
  }

  public addAluno(aluno: Aluno): void {
    this.alunos.push(aluno);
  }

  public getAlunos(): Aluno[] {
    return this.alunos;
  }
}

class Curso {
  private nome: string;
  private codigo: number;

  constructor(codigo: number, nome: string) {
    this.nome = nome;
    this.codigo = codigo;
  }

  public getNome(): string {
    return this.nome;
  }

  public getCodigo(): number {
    return this.codigo;
  }
}

class Escola {
  private static cursos: Curso[]; //Dados dos Cursos
  private static alunos: Aluno[]; //Dados dos Cursos

  public static getCurso(codCurso: number): Curso | undefined {
    return this.cursos.find((curso) => curso.getCodigo() == codCurso);
  }

  public static getAluno(codAluno: number): Aluno | undefined {
    return this.alunos.find((aluno) => aluno.getMatricula() == codAluno);
  }
}

class TextField {
  private text: string;

  public setText(text: string) {
    this.text = text;
  }
}

class DisplayList {
  private items: object[];

  constructor() {
    this.items = [];
  }

  public add(item: object) {
    this.items.push(item);
  }
}

class FacadeCoordenador {
  private static coordenador: FacadeCoordenador;
  private turmas: Turma[];

  private constructor() {
    this.turmas = [];
  }

  public getTurmas() {
    return this.turmas;
  }

  public static getCoordenador(): FacadeCoordenador {
    if (this.coordenador == null) this.coordenador = new FacadeCoordenador();

    return this.coordenador;
  }

  public matricular(codAluno: number, codCurso: number, turma?: Turma) {
    if (turma == null) {
      turma = new Turma();
      let curso: Curso | undefined = Escola.getCurso(codCurso);

      if (curso) turma.setCurso(curso);

      this.turmas.push(turma);
    }

    let aluno = Escola.getAluno(codAluno);

    if (aluno) turma.addAluno(aluno);
  }

  public getStatus(turma: Turma) {
    const curso = turma.getCurso();

    return {
      nomeCurso: curso.getNome(),
      alunos: turma.getAlunos(),
    };
  }
}

class MatriculaGUI {
  private cursoField: TextField;
  private displayList: DisplayList;
  private coordenador: FacadeCoordenador;

  constructor() {
    this.cursoField = new TextField();
    this.displayList = new DisplayList();
    this.coordenador = FacadeCoordenador.getCoordenador();
  }

  public matricular(codAluno: number, codCurso: number, turma: Turma) {
    this.coordenador.matricular(codAluno, codCurso, turma);
  }

  public exibirStatus(turma: Turma) {
    const status = this.coordenador.getStatus(turma);

    this.cursoField.setText(status.nomeCurso);

    for (let index = 0; index < status.alunos.length; index++) {
      const aluno = status.alunos[index];
      this.displayList.add(aluno);
    }
  }
}
