export const compileShader = (
  webgl: WebGLRenderingContext,
  shaderSource: string,
  shaderType: GLenum
) => {
  const shader = webgl.createShader(shaderType);

  if (!shader) throw new Error(`Shader ${shaderType} was not found`);

  webgl.shaderSource(shader, shaderSource);

  webgl.compileShader(shader);

  const success = webgl.getShaderParameter(shader, webgl.COMPILE_STATUS);

  if (!success) {
    const shaderInfo = webgl.getShaderInfoLog(shader);

    webgl.deleteShader(shader);

    throw new Error("Could not compile shader:" + shaderInfo);
  }

  return shader;
};
