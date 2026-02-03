"use client";
import { motion } from "framer-motion";

const container = {
  hidden: { opacity: 0 },
  show: {
    opacity: 1,
    transition: {
      staggerChildren: 0.2,
    },
  },
};

const item = {
  hidden: { opacity: 0, y: 10 },
  show: { opacity: 1, y: 0 },
};


export default function Home() {
  return (
    <div style={{ padding: 40 }}>
      <motion.ul
        variants={container}
        initial="hidden"
        animate="show"
      >
        <motion.li variants={item}>Item 1</motion.li>
        <motion.li variants={item}>Item 2</motion.li>
        <motion.li variants={item}>Item 3</motion.li>
      </motion.ul>
    </div>
  );
}
