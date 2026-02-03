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

    </div>
  );
}
