import type { NextRequest } from "next/server";
import { headers } from "next/headers";

export async function GET(request: NextRequest){
    const headerList = headers();
    return new Response("<h1>Reponse </h1>",{
        headers:
        {
            "Content-Type" : "text/html",
            "Set-Cookie": "Toffee=Kitkat",
        },
    });
}

