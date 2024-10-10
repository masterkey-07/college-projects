// Vertex shader source code
export const VERTEX_SHADER_SOURCE = `
    attribute vec4 a_position;
    attribute vec4 a_color;
    varying vec4 v_color;
    void main() {
        gl_Position = a_position;
        v_color = a_color;
    }
`;

// Fragment shader source code
export const FRAGMENT_SHADER_SOURCE = `
    precision mediump float;
    varying vec4 v_color;
    void main() {
        gl_FragColor = v_color;
    }
`;
