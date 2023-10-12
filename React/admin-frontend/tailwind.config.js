/** @type {import('tailwindcss').Config} */
export default {
  content: [
    "./index.html",
    "./src/**/*.{js,ts,jsx,tsx}",
  ],
  darkMode: false,
  theme: {
    extend: {
      colors: {
        primary: '#205375',
        secondary: '#D9D9D9',
        textlight: '#2F2F2F',
        blue: {
          700: '#112B3C',
          400: '#205375',
        }
      }
    },
  },
  plugins: [],
}