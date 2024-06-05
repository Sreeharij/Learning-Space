import {comments} from "../data";

export async function GET(
    request: Request,
    {params} : {params: { id: string }}){
        if(parseInt(params.id) > comments.length){
            return new Response("Not Found",{status: 404});
        }
        const comment = comments.find(
            (comment) => comment.id === parseInt(params.id)
        );

        return new Response(JSON.stringify(comment));
}

export async function PATCH(
    request: Request,
    {params} : {params: {id: string}}
){
    const body = await request.json();
    const {text} = body;
    const index = comments.findIndex(
        comment => comment.id == parseInt(params.id)
    );
    comments[index].text = text;
    
    return Response.json(comments[index]);
    
}

export async function DELETE(
    request: Request,
    {params}: {params : {id: string}}
){
    const index = comments.findIndex(
        comment => comment.id === parseInt(params.id)
    );
    const deletedComment = comments.splice(index,1);
    return Response.json(deletedComment);
    
}