import Card from "@components/card"
import Link from "next/link";
export default function Notifications(){
    return(
        <Card>
            <div>Archived Notifications</div>
            <Link href="/dashboard/">Default</Link>
        </Card>
    ); 
}