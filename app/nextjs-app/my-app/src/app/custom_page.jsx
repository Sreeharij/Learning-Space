"use client";
import React, { useState } from 'react';
import Link from 'next/link';
const styles = {
  container: {
    fontFamily: "'Segoe UI', Tahoma, Geneva, Verdana, sans-serif",
    textAlign: 'center',
    color: '#ddd',
    backgroundColor: '#1a1a1a',
    height: '100vh',
    margin: 0,
    padding: 0,
    overflow: 'hidden',
  },
  navbar: {
    display: 'flex',
    justifyContent: 'space-between',
    alignItems: 'center',
    padding: '10px 20px',
    backgroundColor: '#333',
    color: '#fff',
    boxShadow: '0 4px 8px rgba(0, 0, 0, 0.2)',
  },
  logo: {
    fontSize: '1.5em',
    fontWeight: 'bold',
    transform: 'perspective(500px) rotateX(20deg)',
  },
  navLinks: {
    display: 'flex',
    gap: '15px',
  },
  link: {
    color: '#fff',
    textDecoration: 'none',
    fontSize: '1.1em',
    transition: 'color 0.3s ease, transform 0.3s ease',
    transform: 'perspective(500px) rotateY(10deg)',
  },
  linkHover: {
    color: '#4CAF50',
    transform: 'perspective(500px) rotateY(0deg) scale(1.1)',
  },
  header: {
    marginTop: '20px',
    fontSize: '2.5em',
    color: '#4CAF50',
    textShadow: '2px 2px 8px rgba(0, 0, 0, 0.7)',
    transform: 'perspective(500px) rotateX(10deg)',
  },
  subheader: {
    fontSize: '1.2em',
    color: '#bbb',
    textShadow: '1px 1px 5px rgba(0, 0, 0, 0.5)',
    transform: 'perspective(500px) rotateX(5deg)',
  },
};

function Home() {
  const [hoverIndex, setHoverIndex] = useState(-1);

  const handleMouseEnter = (index) => {
    setHoverIndex(index);
  };

  const handleMouseLeave = () => {
    setHoverIndex(-1);
  };

  const navItems = [
    { text: 'Order Product', href: '/order-product' },
    { text: 'Login', href: '/login' },
    { text: 'Register', href: '/register' },
    { text: 'Complex-Dashboard',href:'/complex-dashboard'},
  ];

  return (
    <div style={styles.container}>
      <nav style={styles.navbar}>
        <div style={styles.logo}>MySite</div>
        <div style={styles.navLinks}>
          
          {navItems.map((item, index) => (
            <Link
              href={item.href}
              key={index}
              style={{
                ...styles.link,
                ...(hoverIndex === index && styles.linkHover),
              }}
              onMouseEnter={() => handleMouseEnter(index)}
              onMouseLeave={handleMouseLeave}
            >
              {item.text}
            </Link>
          ))}
        </div>
      </nav>
      <h1 style={styles.header}>Welcome to MySite</h1>
      <p style={styles.subheader}>This is the homepage. Enjoy your stay!</p>
    </div>
  );
}

export default Home;
