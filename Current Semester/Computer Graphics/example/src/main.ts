import { FRAGMENT_SHADER_SOURCE, VERTEX_SHADER_SOURCE } from "./constants";
import { createProgram } from "./utils/program";
import { compileShader } from "./utils/shader";
import { getWebGLFromCanvas } from "./utils/webgl";

const TRIANGLE_POSITIONS = new Float32Array([
  0.0,
  0.5, // Vertex 1: top center
  -0.5,
  -0.5, // Vertex 2: bottom left
  0.5,
  -0.5, // Vertex 3: bottom right
]);

const TRI_COLORS = new Float32Array([
  1.0,
  0.0,
  0.0,
  1.0, // Vertex 1: red
  0.0,
  1.0,
  0.0,
  1.0, // Vertex 2: green
  0.0,
  0.0,
  1.0,
  1.0, // Vertex 3: blue
]);

const setupCanvas = () => {
  const webgl = getWebGLFromCanvas("screen");

  // Compile vertex and fragment shaders
  const vertexShader = compileShader(
    webgl,
    VERTEX_SHADER_SOURCE,
    webgl.VERTEX_SHADER
  );

  const fragmentShader = compileShader(
    webgl,
    FRAGMENT_SHADER_SOURCE,
    webgl.FRAGMENT_SHADER
  );

  // Link shaders into a program
  const program = createProgram(webgl, vertexShader, fragmentShader);

  // Look up attribute locations
  const positionAttributeLocation = webgl.getAttribLocation(
    program,
    "a_position"
  );
  const colorAttributeLocation = webgl.getAttribLocation(program, "a_color");

  // Create a buffer and put three 2D points in it (a triangle)
  const positionBuffer = webgl.createBuffer();
  webgl.bindBuffer(webgl.ARRAY_BUFFER, positionBuffer);
  webgl.bufferData(webgl.ARRAY_BUFFER, TRIANGLE_POSITIONS, webgl.STATIC_DRAW);

  // Create a buffer for colors
  const colorBuffer = webgl.createBuffer();
  webgl.bindBuffer(webgl.ARRAY_BUFFER, colorBuffer);
  webgl.bufferData(webgl.ARRAY_BUFFER, TRI_COLORS, webgl.STATIC_DRAW);

  // Tell WebGL how to convert from clip space to pixels
  webgl.viewport(0, 0, webgl.canvas.width, webgl.canvas.height);

  // Clear the canvas with a dark gray color
  webgl.clearColor(0, 0, 0, 1.0);
  webgl.clear(webgl.COLOR_BUFFER_BIT);

  // Use the program
  webgl.useProgram(program);

  // Enable the position attribute
  webgl.enableVertexAttribArray(positionAttributeLocation);
  webgl.bindBuffer(webgl.ARRAY_BUFFER, positionBuffer);

  // Tell the attribute how to get data out of positionBuffer (ARRAY_BUFFER)
  const size = 2; // 2 components per iteration
  const type = webgl.FLOAT; // the data is 32bit floats
  const normalize = false; // don't normalize the data
  const stride = 0; // move forward size * sizeof(type) each iteration
  const offset = 0; // start at the beginning of the buffer
  webgl.vertexAttribPointer(
    positionAttributeLocation,
    size,
    type,
    normalize,
    stride,
    offset
  );

  // Enable the color attribute
  webgl.enableVertexAttribArray(colorAttributeLocation);
  webgl.bindBuffer(webgl.ARRAY_BUFFER, colorBuffer);
  webgl.vertexAttribPointer(
    colorAttributeLocation,
    4,
    webgl.FLOAT,
    false,
    0,
    0
  );

  // Draw the triangle
  const primitiveType = webgl.TRIANGLES;
  const count = 3; // 3 vertices
  webgl.drawArrays(primitiveType, 0, count);
};

const bootstrap = () => {
  try {
    setupCanvas();
  } catch (error) {
    if (error instanceof Error) alert(error.message);
  }
};

export default bootstrap();
