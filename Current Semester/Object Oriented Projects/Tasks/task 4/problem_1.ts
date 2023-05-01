interface Shape {
  getBounds(): [number, number];
}

class TextView {
  private text: string;
  private font: number;

  constructor(text: string, font: number) {
    this.text = text;
    this.font = font;
  }

  getFontMetrics(): number {
    return this.font;
  }
  getText() {
    return this.text;
  }
}

class DrawingEditor {
  draw(shape: Shape) {
    console.log("draw at " + shape.getBounds());
  }
}

class LineShape implements Shape {
  private weight: number;
  private length: number;

  constructor(weight: number, length: number) {
    this.weight = weight;
    this.length = length;
  }

  getBounds(): [number, number] {
    return [this.length, this.weight];
  }
}

// Foi utilizado um Adapter de Classe por ter disponibilidade a Interface.
class TextAdapter extends TextView implements Shape {
  getBounds(): [number, number] {
    return [this.getText().length, this.getFontMetrics()];
  }
}

const editor = new DrawingEditor();

editor.draw(new LineShape(1, 6));
editor.draw(new TextAdapter("aaa", 12));
