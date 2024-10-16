export const getWebGLFromCanvasId = (canvasId: string) => {
  const canvas = document.getElementById(canvasId) as
    | HTMLCanvasElement
    | undefined;

  if (!canvas) throw new Error("Canvas not found");

  const webgl = canvas.getContext("webgl");

  if (!webgl) throw new Error("WebGL not supported in this browser.");

  return webgl;
};
