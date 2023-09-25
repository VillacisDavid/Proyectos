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
        blue: {
          700: '#112B3C',
          400: '#205375',
        }
      }
    },
  },
  plugins: [],
}