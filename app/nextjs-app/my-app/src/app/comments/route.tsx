import {comments} from './data'
import type { NextRequest } from 'next/server';
export async function GET(request: NextRequest){
    const searchParams = request.nextUrl.searchParams;
    const query = searchParams.get("query"); 
    const filtered_comments = query ? 
    comments.filter(comment => comment.text.includes(query)) //Doesnt match capital 
    : comments;

    return Response.json(filtered_comments);
}

export async function POST(request: Request){
    const comment = await request.json();
    const newComment = {
        id: comments.length + 1,
        text: comment.text,
    }
    comments.push(newComment);
    return new Response(JSON.stringify(newComment),{
        status: 201,
        headers: {
            "Content-Type" : "application/json",
        }
    })
}
