"use client";
import { useRouter } from "next/navigation";

export default function Home(){
    const router = useRouter();
    const handleClick = () => {
        router.push('/dashboard');    
    }
    return(
        <>
            <h1>Home Page</h1>
            <button onClick={handleClick}>learn parrallel routes</button>
        </>
    );
}