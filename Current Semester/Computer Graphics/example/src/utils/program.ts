export const createProgram = (
  webgl: WebGLRenderingContext,
  vertexShader: WebGLShader,
  fragmentShader: WebGLShader
) => {
  const program = webgl.createProgram();

  if (!program) throw new Error("Program not found");

  webgl.attachShader(program, vertexShader);

  webgl.attachShader(program, fragmentShader);

  webgl.linkProgram(program);

  const success = webgl.getProgramParameter(program, webgl.LINK_STATUS);

  if (!success) {
    const programInfo = webgl.getProgramInfoLog(program);

    webgl.deleteProgram(program);

    throw new Error("Program failed to link: " + programInfo);
  }

  return program;
};
