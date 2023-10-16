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
        orange: '#E43A15',
        textlight: '#2F2F2F',
        gray: {
          100: '#eeeeee',
          200: '#E3E3E3',
          300: '#D9D9D9',
          400: '#979797',
        },
        blue: {
          700: '#112B3C',
          400: '#205375',
        },
      }
    },
  },
  plugins: [],
}