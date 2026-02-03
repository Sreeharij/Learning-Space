"use client";
import { motion } from "framer-motion";

export default function Home() {
  return (
    <div style={{ padding: 40 }}>
      <motion.div
        initial={{ opacity: 0, x: -100, y: 50 }}
        animate={{ opacity: 1, x: 200, y: 300 }}
        transition={{ type: "spring", stiffness: 120 }}
        style={{
          width: 100,
          height: 100,
          background: "white",
        }}
      />
      <motion.button
        whileHover={{ scale: 1.1 }}
        whileTap={{ scale: 0.95 }}
        style={{
          padding: "12px 20px",
          fontSize: 16,
        }}
      >
        Click Me
      </motion.button>

      <motion.div
        animate={{ rotate: 360 }}
        transition={{
          repeat: Infinity,
          duration: 2,
          ease: "linear",
        }}
        style={{
          width: 100,
          height: 100,
          background: "white",
        }}
      />

    </div>
  );
}
